// Room: nongjia.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "茅舍");

	set("long", @LONG
县城捕头杨铮在这租了间小屋，房东姓于，对待杨铮就象亲生儿子一样，独生
女儿莲姑并不漂亮，但却健康温柔。杨铮一天没有回来，她就会急得躲到洗衣服的
小溪边去偷偷流泪。每次他拉住她的手时，她都会脸红心跳。
LONG);

	set("type","indoors");
	set("exits",([
		"east":__DIR__"yard",
	]) );

        set("objects", ([
        ]) );
        set("indoors", "libie");
	set("coor/x",-7);
	set("coor/y",10);
	set("coor/z",0);

	setup();
}
