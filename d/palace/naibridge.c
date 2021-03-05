
inherit ROOM;

void create()
{
        set("short", "奈何桥");
        set("long", @LONG
掠过这座石像，笔直而行！ 只见前面竞是一道溪流。上架黑石小桥，桥上赫
然写著： ＂奈何桥＂ 三字！ 极目望去，＂奈何桥＂那边，弥布著一片鬼气。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"river",
  "north" : __DIR__"stonelin",
  "south" : __DIR__"ghost",
]));
        set("objects", ([
//        __DIR__"obj/mirror" : 1,
                        ]) );

        set("outdoors", "palace");

	set("coor/x",-90);
	set("coor/y",60);
	set("coor/z",10);
//	set("refresh_all_items", 1);
	setup();
   
}


void reset(){
	object obj;
	
	::reset();
	if(!present("mirror", this_object())){
		obj = new(__DIR__"obj/mirror");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}	
	return;
}
