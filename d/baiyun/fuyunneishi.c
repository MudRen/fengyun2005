//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "懒人居");
    set("long", @LONG
世上懒人不少，但朱停却可以说是独一无二的懒人，虽然他可以一天从早到晚都
懒懒地躺在太师椅上，什么都不做，但也可以突然跳起来在小屋里捣腾来个五天七夜，
无一例外的是，世界上便多了一件独一无二的东西。也许是最好的暗器，远胜什么暴
雨梨花钉；也许是最匪夷所思的工具，丝毫不输当年公输班的手艺；也许便是令人目
瞪口呆的机械人；朱停懒，不仅因为有个勤快的老板娘，更因为他的一行一动全部可
由他的机械人来帮他。。
LONG
    );
    set("exits",
      ([
	"south" : __DIR__"fuyun",
      ]));
    set("objects",
      ([
	__DIR__"npc/zhuting" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-140);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
