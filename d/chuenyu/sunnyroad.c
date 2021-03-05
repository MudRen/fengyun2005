// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "山脚乡田");
        set("long", @LONG
两侧是茂盛的稻田，还有一条清澈见底的小溪。许多乡民在田里辛苦的忙碌着。
再北面是黑松山。眺望山顶，你似乎可以看到一个颇具规模的城堡。城堡的最顶端
插着一面大旗，大旗上绣着两个斗大的金字：淳于。
LONG
        );
        set("exits", ([ 
  		"south" : __DIR__"dustyroad2",
	]));

	set("objects", ([
               __DIR__"npc/xiaojuan" : 1,
	]) );
	set("no_fight",1);
	
	set("outdoors", "chuenyu");
	set("coor/x",-30);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();
}

void reset()
{
	object room;
	::reset();
        if(query("exits/north"))
        	delete("exits/north");
}



int valid_leave(object me, string dir)
{
	if(query("exits/north"))
		call_out("close_path",10);
	return 1;	
}


int close_path()
{
	reset();
	return 1;
}


