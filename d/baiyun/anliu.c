//Created by justdoit at May 2001 
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "暗流");
        set("long", @LONG
自潭底而下，热流汩汩，水势颇急，而四下一片漆黑，而水深处浮力甚强，若
气息一个不顺，便会被冲上去。急沉而下似乎较远处有些许亮光，一股急流卷着身
子不由自主冲了过去。
LONG
           );
        set("exits", 
           ([ 
       "down" : __DIR__"anliu1",
       "up" : __DIR__"qianlonghu",
        ]));
    set("objects", 
       ([ 
//	     __DIR__"obj/sand" : 1,
        ]));
        set("indoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
