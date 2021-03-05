inherit ROOM;
void create()
{
        set("short", "大宅院");
        set("long", @LONG
这是一所只有两扇窗宽、四层楼高的宅子，是镇上唯一几幢像样的房子之一。
原来住着的一个寡妇被赶回了娘家，大宅院改成了常笑的临时官邸。二层楼比第一
层更凸向街面，而三层楼、四层楼更比二层楼凸出。整所的房屋雕刻着古老的花纹，
那下面的两根大柱子，那尖尖的瓦屋顶，和顶楼的象鸟嘴似的突出部分，使这所宅
子看起来象一只蜷曲着的大鸟。
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"mroad5",
		"up":	__DIR__"house3a",
		"east":	__DIR__"house3b",
	]));
	set("objects", ([
        	__DIR__"npc/zhangtie" : 1,
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


int valid_leave(object me, string dir){
	object zhang;
	
	if (dir=="up" && zhang=present("zhang tie",this_object()) 
		&& me->query("family/master_id")!="master yin") {
		message_vision("张铁说：“不可打扰常大人休息！！！”\n",me);
		return notify_fail("");
	}
	return 1;
}

