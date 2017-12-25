#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;
  for (i = 0; i < argc; i++) {
    FILE *f;
    int c;

    // ここで既にバッファに読み込まれている
    // fはファイルディスクリプタとバッファをもつ
    f = fopen(argv[i], "r");
    if (!f) {
      perror(argv[i]);
      exit(1);
    }

    // 1バイトずつfのバッファから読み込み
    while ((c = fgetc(f)) != EOF) {
      // 1バイトずつstdoutのストリームに出力
      if (putchar(c) < 0)
        exit(1);
    }

    fclose(f);
  }

  exit(0);
}
