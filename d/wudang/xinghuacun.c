inherit ROOM;

void create()
{
	set("short", "杏花村酒家");

	set("long", @LONG
远山前，流水旁是间杏花村酒家，虽然只是个小小的酒肆，外面也有小小的栏
杆、小小的庭院，里面则是小小的门户、小小的厅堂，当炉卖酒的，是一个眼睛小
小、鼻子小小、嘴巴小小的女人。
LONG);

	set("exits",([
        	"east":	__DIR__"xzroad1",
	]) );

        set("indoors", "wudang");
        set("objects", ([
        	__DIR__"npc/xinghua": 1,
        	__DIR__"npc/xusan": 1,
        ]));
	set("coor/x",-10);
	set("coor/y",90);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
