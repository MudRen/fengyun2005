inherit ROOM;

void create()
{
//	object con,item;

	set("short", "农家");
	set("long", @LONG
这件屋子明显比周围的要破旧一些，门虚掩著，屋内摆设非常简朴，只有几样
生活必需品，屋角堆着的农具上积满了灰尘，似乎已经很久没人动过了。[33m墙[32m上挂著
一柄铁剑分外醒目，使人忍不住开始猜想此屋主人的来历。
LONG
	);
	set("exits", ([
		"east" : __DIR__"xzroad3",
	]));
	set("objects", ([
		__DIR__"obj/wall": 1,
		__DIR__"npc/dahanwife": 1,
	]));
	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",-50);
	setup();
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("wall", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/sword2");
                item->move(con);
	}
}