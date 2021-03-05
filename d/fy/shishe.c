inherit ROOM;
void create()
{
    set("short", "青云诗社");
    set("long", @LONG
寒窗十载，穷首皓经，古往今来读书人梦想的是有朝一日可以平步青云，一逞
抱负。前朝皇帝为了鼓励天下臣民好学求仕，在及第街南首御笔亲点，建了一所青
云诗社，让天下的诗人墨客交流学问，也为上京赶考的书生们提供一处住所。诗社
中墨香书声不时于耳，可谓天下才俊集结之地。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"jidijie",
	"up":	 __DIR__"clubpoem",
      ]));
    set("objects", ([
	__DIR__"npc/student" : 2,
      ]) );

    set("coor/x",-20);
    set("coor/y",60);
    set("coor/z",0);
    set("map","fynorth");
    setup();
}
