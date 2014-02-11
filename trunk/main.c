/*******************************************************************************
*
*  Author  : lukas42singer@gmail.com
*  Created : 2014/02/11
*  Filename: main.c
*  Title   :   #     ###    ###     #      #    #   #  #    
*             # #   #   #  #   #    #      #    #   #  #    
*            #   #  #      #        #      #    #   #  #    
*            #   #   ###   #        #      #    #####  #    
*            #####      #  #        #      #    #   #  #    
*            #   #  #   #  #   #    #      #    #   #  #    
*            #   #   ###    ###     #      #    #   #  #####
*  Description:
*            Because i really like the fancy, awesome headlines made of ascii-
*            chars i developed this little tool to generate them!
*  License : GNU GPL v3
*            http://www.gnu.org/licenses/gpl.txt
*  Changes : Added to https://asciihl.googlecode.com/svn/trunk/
*            Project Site: https://code.google.com/p/asciihl/
*
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#define TITLE "ASCIIHL"
#define VERSION "v0.1"
#define LICENSE "GNU GPL v3"
#define AUTHOR "Lukas Singer"
#define DATE "2014/02/11"

struct params_t {
  unsigned int flags;
  int font;
  int space;
  char input[255];
  char output[255];
};

void parse(int argc, char** argv, struct params_t* params);
void error(char enr);
void help();
void version();
void asciihl(struct params_t* params);

int main(int argc, char** argv){
  struct params_t p;
  parse(argc,argv,&p);
  if(p.flags&1u){
    help();
    exit(0);
  }
  if(p.flags&4u){
    version();
    exit(0);
  }
  asciihl(&p);
  return 0;
}

void asciihl(struct params_t* params){
  char* c3x5[] = {
    "   #       #     #   #        #   #                       #                    # ##  #### ###### # # # #   ## ##  # ## # # ##  # ##  ###### ## ## ## ## ####",
    "   #       #    #    #   #  # #   #                      ###                  # ## ##  # ##  #  # ## # #   ## ##  ####### ## ## ## ##   # # ## ## ## ## #  #",
    " ####  ## ## #  ## # ##       # # # # ###  # ##  ## ## ## # # ## ##### ## ######### #  # ### ## #  ### #   ### #  ####### ### # ###  #  # # ## #### #  #  # ",
    "# ## ##  # #### # # ## # #  # ##  # #### ## ## ## # # ### # # ## #### # # # # # ## ##  # ##  #  # ## # # # ## ##  # ##### ##  # ## #  # # # ## ##### # # #  ",
    "#####  ## ## ## #  ### # #  # # #  ##### # # ##  ## # ##   # ## # # ## # # #### ###  #### ####   ### # #  # # ##### ## # # #   ### ###  # ### # # ## # # ###",
    "                  ##       #                 #    #                     #                                                                                   "
  };
  char* c5x7[] = {
    "     #             #        ##     #              #      #                                       #                                  #  ####  ### #### ########## ### #   #  #     # #   ##    #   ##   # ### ####  ### ####  ### ######   ##   ##   ##   ##   ######",
    "     #             #       #       #              #      #                                      ###                                # # #   ##   ##   ##    #    #   ##   #  #     # #  # #    ## ####  ##   ##   ##   ##   ##   #  #  #   ##   ##   ##   ##   #    #",
    "     #             #       ##      #      #    #  #      #                                 ####  #                                #   ##   ##    #   ##    #    #    #   #  #     # # #  #    # # ###  ##   ##   ##   ##   ##      #  #   ##   ##   # # #  # #    # ",
    " ########  #### #### ###   #   ### ####           #  #   #  #### ####  ### ####  ###  ### #      #  #   ##   ##   ##   ##   #######   ##### #    #   ####  ###  #    #####  #     # ##   #    # # ## # ##   ##### #   #####  ###   #  #   ##   ## # #  #    #    #  ",
    "#   ##   ##    #   ##   #  #  #   ##   #  #    #  ###    #  # # ##   ##   ##   ##   # #    ###   #  #   ##   ## # # ###  # #    # ######   ##    #   ##    #    #  ###   #  #     # # #  #    #   ##  ###   ##    # # ## #      #  #  #   ##   ## # # # #   #   #   ",
    "#   ##   ##    #   #####   #  #   ##   #  #    #  #  #   #  # # ##   ##   ##   ##   # #       #  #  #   # # # ## ## # #   #   ##  #   ##   ##   ##   ##    #    #   ##   #  #   # # #  # #    #   ##  ###   ##    #  ###  # #   #  #  #   # # # ## ###   #  #  #    ",
    " ########  #### #### ####  #   #####   #  #    #  #   #   # # # ##   # ### ####  #### #   ####    #  ####  #  #   ##   #  #  ######   #####  ### #### ######     #####   #  #    #  #   #######   ##   # ### #     #####   # ###   #   ###   #  #   ##   #  #  #####",
    "                                  #            #                           #        #                                                                                                                                                                               ",
    "                               ###            #                            #        #                                                                                                                                                                               "
  };
  int idx;
  int lines;
  int width;
  char** font;
  switch(params->font){
    case 1: //3x5
      lines=6;
      width=3;
      font=c3x5;
      break;
    case 2: //5x7
      lines=9;
      width=5;
      font=c5x7;
      break;
    default:
      return;
  }
  for(int i=0;i<lines;i++){
    for(int j=0;j<strlen(params->input);j++){
      if(params->input[j]>='a'&&params->input[j]<='z'){
        idx=width*(params->input[j]-'a');
      }else if(params->input[j]>='A'&&params->input[j]<='Z'){
        idx=width*(params->input[j]-'A')+(width*26);
      }else if(params->input[j]=='_'){
        for(int k=0;k<width+params->space;k++) printf(" ");
        continue;
      }else{
        error(2); //2=unsupported character
      }
      for(int k=0;k<width;k++) printf("%c",font[i][idx+k]);
      for(int k=0;k<params->space;k++) printf(" ");
    }
    printf("\n");
  }
}

void parse(int argc, char** argv, struct params_t* params){
  unsigned int last=0;
  char arg[255];
  params->font=2; //default font "5x7"
  params->space=2; //default spaces between chars 2;
  params->flags=0;
  strcpy(params->input,"hello_world"); //default text "hello world"
  for(int i=1;i<argc;i++){
    if(strlen(argv[i])>255) error(1);
    strcpy(arg,argv[i]);
//    printf("now parsing: %s\n",arg);
    switch(last){
      case 8: //font
        if(strcmp(arg,"3x5")==0) params->font=1;
        if(strcmp(arg,"5x7")==0) params->font=2;
        last=0;
        break;
      case 16: //space
        params->space=0;
        for(int j=0;j<strlen(arg);j++){
          if(arg[j]<'0'||arg[j]>'9') error(3);
          params->space=params->space*10+(arg[j]-'0');
        }
        last=0;
        break;
      case 32: //input
        strcpy(params->input,arg);
        last=0;
        break;
      case 64: //output
        strcpy(params->output,arg);
        last=0;
        break;
      default:
        if(strlen(arg)>=2){
          last=0;
          if(strcmp(arg,"-h")==0||strcmp(arg,"--help")==0) last=1;
          if(strcmp(arg,"-c")==0||strcmp(arg,"--clipboard")==0) last=2;
          if(strcmp(arg,"-v")==0||strcmp(arg,"--version")==0) last=4;
          if(strcmp(arg,"-f")==0||strcmp(arg,"--font")==0) last=8;
          if(strcmp(arg,"-s")==0||strcmp(arg,"--space")==0) last=16;
          if(strcmp(arg,"-i")==0||strcmp(arg,"--input")==0) last=32;
          if(strcmp(arg,"-o")==0||strcmp(arg,"--output")==0) last=64;
          if(last==0) error(0);
        }else{
          error(0);
        }
        break;
    }
//    printf("aktflag: %d\n",last);
    params->flags|=last;
  }
}

void error(char enr){
  switch(enr){
    case 1:
      printf("stringargument is too long (max. length = 255)\n");
      break;
    case 2:
      printf("unsuportet character\n");
      break;
    case 3:
      printf("space argument must be a number\n");
      break;
    default:
      break;
  }
  printf("try -h or --help\n");
  exit(-1);
}

void help(){
  version();
  printf("\nUsage: asciihl [OPTION(S)]\n\n");
  printf("Options:\n");
  printf("     -h, --help            displays this helptext\n");
  printf("     -v, --version         displays version info\n");
  printf("XXX  -c, --clipboard       copy the output to the clipboard\n");
  printf("     -f, --font <FONT>     select a font\n");
  printf("     -s, --space <NUMBER>  select how many spaces between characters\n");
  printf("     -i, --input <TEXT>    the text to convert\n");
  printf("XXX  -o, --output <FILE>   a filename to put the output in\n\n");
  printf("Fonts:\n");
  printf("     3x5\n");
  printf("     5x7\n\n");
  printf("Text:\n");
  printf("     supported charecters are a..z and A..Z\n");
  printf("     use \"_\" (underline) to create space character\n\n");
  printf("Examples:\n");
  printf("     asciihl -i hello_world\n");
  printf("     asciihl -f 3x5 -i I_love_ASCIIHL\n");
  printf("     asciihl -f 5x7 -s 3 -i GNU\n\n");
}

void version(){
  printf("%s %s %s\nAuthor: %s\nLicense: %s\n",TITLE,VERSION,DATE,AUTHOR,LICENSE);
}

