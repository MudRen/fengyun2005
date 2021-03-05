// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "习技堂");
        set("long", @LONG
这是弟子自行学习武功所在，许多少林武技都是天资聪颖的后辈弟子在此悟出，
堂中陈设简单，惟有中间供奉一尊观音像，据传跪拜以后，领悟武功会突飞猛进，
所以堂中弟子甚多，满屋都是打坐冥思之人。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"damo",
]));
        set("objects", ([
                __DIR__"obj/guanyin" : 1,
       ]) );

	set("coor/x",10);
	set("coor/y",90);
	set("coor/z",20);
	setup();
	replace_program(ROOM);

}
