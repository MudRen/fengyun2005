// Room: mishi.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "密室");

	set("long", @LONG
这是间很小的屋子，屋子很暗，但却收拾得整洁干净，四周也空无一物。屋中
站着个人，偶尔踱着方步，眉头微皱，似乎在想着什么麻烦的事情。门外就是高高
的山崖，旁边有个深不见底的寒潭，游目四顾，只见繁花青草，仿佛一个极大的花
园，略略有些使人奇怪的是，崖壁上原本寸草不生，但却很突兀的生出一串嫩绿的
青苔来,蜿蜒向上。
LONG);
	//{{ --- by MapMaker
	set("type","house");
	//}}
	set("objects", ([
	__DIR__"npc/yang" :1,
	__DIR__"obj/lichen" :1,
	]) );
        set("indoors", "shanliu");
	set("coor/x",-5);
	set("coor/y",70);
	set("coor/z",-20);
	setup();
	replace_program(ROOM);
}
