inherit ROOM;
void create()
{
        set("short", "西宅");
        set("long", @LONG
西宅是一所只有两扇窗宽、四层楼高的宅子。二层楼比第一层更凸向街面，而
三层楼、四层楼更比二层楼凸出。整所的房屋雕刻着古老的花纹，它那下面的两根
大柱子，它那尖尖的瓦屋顶，和顶楼的象鸟嘴似的突出部分，这一切使这所宅子看
起来象一只蜷曲着的大鸟。
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"mroad2",
		"up":  __DIR__"house1a",
	]));
	set("objects", ([
        	__DIR__"npc/tan1" : 1,
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	set("map","taiping");
	setup();
}



int valid_leave(object me,string dir) {
        object ob,end_room,*inv;
	int i;
	
	if( userp(me) && dir == "up" && ob=present("tan tianlong",this_object())) {
		return notify_fail(ob->name()+"朝你一瞪眼，挡住了你的去路。\n");		
	}
	return 1;
}