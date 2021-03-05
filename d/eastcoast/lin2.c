inherit ROOM;
void create()
{
	set("short", "无名的空地");
	set("long",@LONG
空地，乱石，杂草，阴风。海腥味更重了，令人觉得嘴里似乎塞满了盐，又苦
又涩。四周异常昏暗，你连自己的影子都看不清在哪里。杂草在阴风的鼓动下沙沙
地扭个不停，远处隐约传来海涛击岸的声音。
LONG);
	set("exits", ([
			"west" : __DIR__"lin1",
			"east" : __DIR__"fchuan",
	]) );
	set("objects", ([
			AREA_BAT"npc/wei": 1,
	]) );
	set("outdoors", "bat");
	set("coor/x",1010);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	//replace_program(ROOM);         
}


int valid_leave(object me, string dir)		//add by jusdoit at Dec 17,2001
{
	object ob;
	if( dir == "west" &&  me->query_temp("marks/gived_qfbook") ) {
		me->delete_temp("marks/gived_qfbook");
		return 1;
		}
	else
		return 1;
}