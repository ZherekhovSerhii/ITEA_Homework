#include <functional>
#include <iostream>

#define BUFFSIZE 1024
#define LINESIZE 256
#define COPYBUFFSIZE 16

enum {
  EXIT = 1,
  PRINT,
  SELECT,
  COPY,
  PASTE,
  MOVE,
  CUT,
  SHOW,
};

void clear(char *begin) {
  if (begin == nullptr || *begin == '\0')
    return;

  while (*begin != '\0') {
    *begin = '\0';
    ++begin;
  }
}

void show(const char *buff) {
  while (*buff != '\0') {
    std::cout << *buff++;
  }
  std::cout << "\n";
}

unsigned int str_len(const char *begin) {
  if (begin == nullptr || *begin == '\0')
    return 0;

  unsigned int length = 0;
  while (*begin != '\0') {
    ++length;
    ++begin;
  }
  return length;
}

bool str_cmp(const char *begin1, const char *begin2) {
  if (begin1 == nullptr || *begin1 == '\0' || begin2 == nullptr ||
      *begin2 == '\0' || (strlen(begin1) < strlen(begin2)))
    return false;

  bool is_equal = true;
  while (*begin1 != '\0' && *begin2 != '\0') {
    if (*begin1 != *begin2) {
      is_equal = false;
      break;
    }
    ++begin1;
    ++begin2;
  }
  return is_equal;
}

int get_cmnd(const char *line) {
  if (str_cmp(line, "exit")) {
    return EXIT;
  } else if (str_cmp(line, "print")) {
    return PRINT;
  } else if (str_cmp(line, "select")) {
    return SELECT;
  } else if (str_cmp(line, "copy")) {
    return COPY;
  } else if (str_cmp(line, "paste")) {
    return PASTE;
  } else if (str_cmp(line, "move")) {
    return MOVE;
  } else if (str_cmp(line, "cut")) {
    return CUT;
  } else if (str_cmp(line, "show")) {
    return SHOW;
  } else
    return 0;
}

unsigned int print(char *buff, const char *line) {
  unsigned int counter = 0;

  if (*buff == '\0') {
    while (*line != '\0') {
      *buff = *line;
      ++buff;
      ++line;
      ++counter;
    }
  } else {
    unsigned int line_len = str_len(line);
    unsigned int buff_len = str_len(buff);

    while (buff_len > line_len) {
      --buff_len;
      *(buff + line_len + buff_len) = *(buff + buff_len);
    }

    while (*line != '\0') {
      *(buff + line_len) = *buff;
      *buff = *line;
      ++buff;
      ++line;
      ++counter;
    }
  }

  return counter;
}

void select(const char *buff, unsigned int &cursor, unsigned int &length) {
  bool cursor_is_not_setted = true;
  while (*buff != '\0') {
    if ((*buff >= '0') && (*buff <= '9')) {
      if (cursor_is_not_setted) {
        cursor = (*buff) - '0';
        cursor_is_not_setted = false;
      } else {
        length = (*buff) - '0';
        break;
      }
    }
    ++buff;
  }
}

void copy(const char *buff, char *copybuff, const unsigned int length) {
  unsigned int counter = 0;
  while (counter < length) {
    *copybuff = *buff;
    ++buff;
    ++copybuff;
    ++counter;
  }
}

int paste(char *buff, const char *copybuff) {
  unsigned int counter = 0;

  while (*copybuff != '\0' && counter < COPYBUFFSIZE) {
    *buff = *copybuff;
    ++buff;
    ++copybuff;
    ++counter;
  }
  return counter;
}

int move(const char *line) {
  int diff = 0;

  if (str_cmp(line, "left ")) {
    diff = -1;
  } else if (str_cmp(line, "right ")) {
    diff = 1;
  } else
    return 0;

  while (*line != '\0') {
    if ((*line >= '0') && (*line <= '9')) {
      return diff *= *line - '0';
    }
    ++line;
  }
}

void cut(char *buff, const unsigned int length) {
  while (*buff != '\0') {
    *(buff - length) = *buff;
    *buff = 0;
    ++buff;
  }
}

int main(int argc, char *argv[]) {
  char buff[BUFFSIZE]{};
  char line[LINESIZE]{};
  char copybuff[COPYBUFFSIZE]{};
  unsigned int cursor = 0;
  unsigned int selectcursor = 0;
  unsigned int length = 0;
  unsigned int cmnd = 0;

  while (cmnd != EXIT) {
    cmnd = 0;
    std::cin >> line;
    cmnd = get_cmnd(line);
    clear(line);
    std::cin.getline(line, LINESIZE);

    switch (cmnd) {
    case EXIT:
      break;

    case PRINT:
      if (str_len(buff) + str_len(line) <= BUFFSIZE) { //здесь учитываются и границы буффера, и наличие '\0'-символа
        cursor += print((buff + cursor), (line + 1));
      }
      break;

    case SELECT:
      select(line, selectcursor, length);
      if (selectcursor >= BUFFSIZE)
        selectcursor = BUFFSIZE - 1;      //теоретически выделить select`ом '\0'-символ можно, поэтому при
              												        //проверке учитываются только границы буффера
      if ((selectcursor + length) >= BUFFSIZE)      //еще одну единицу не отнимал по указанной причине
        length = length + (BUFFSIZE - (selectcursor + length));
      if (length > COPYBUFFSIZE)
        length = COPYBUFFSIZE;
      break;

    case COPY:
      clear(copybuff);
      copy((buff + selectcursor), copybuff, length);
      break;

    case PASTE:
      if (str_len(copybuff) + str_len(buff) < BUFFSIZE)
        cursor += paste((buff + cursor), copybuff);
      break;

    case MOVE: {
      int diff = move((line + 1));
      if (static_cast<signed int>(cursor + diff) >= 0)
        cursor += diff;
      else
        cursor = 0;
    } break;

    case CUT: {
      cut((buff + selectcursor + length), length);
      if (static_cast<signed int>(cursor - length) >= 0)
        cursor -= length;
      else
        cursor = 0;
    } break;

    case SHOW:
      show(buff);
      break;

    default:
      std::cout << "UNDEFINED COMMAND" << std::endl;
      break;
    }
  }
  return 0;
}
