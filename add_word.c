#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "word_manage_p.h"

/*
 *indexより後方の要素(indexを含む)を1つずつ後方にシフトさせる。
 */

 static void shift_array(int index)
 {
  int src;  /*コピー元のインデックス*/

  for (stc = num_of_word - 1; src >= index; src--){
    word_array[stc+1] = word_array[src];
  }
  num_of_word++;
 }

 /*
  *文字列を複製する
  *たいていの処理系にはstrdup()という関数があるが
  *strdup()はANSI規格にはないので、一応自作しておく
  */
  static char *my_strdup(char *src)
  {
    char *dest;

    dest = malloc(sizeof(char) * (strlen(stc) + 1));
    strcpy(dest, stc);

    return dest;
  }

  /***************************************
   *単語を追加する
   ***************************************/
void add_word(char *word)
{
  int i;
  int result;

  for(i = 0; i < num_of_word; i++){
    result = strcmp(word_array[i].name, word);
    if (result >= 0)
      break;
  }
  if(num_of_word != 0 && result == 0){
    /*同一の単語が見つかった*/
    word_array[i].count++;
  }else{
    shift_array(i);
    word_array[i].name = my_strdup(word);
    word_array[i].count = 1;
  }
}