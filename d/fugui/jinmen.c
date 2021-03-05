inherit ROOM;

void create()
{
	set("short", "金府大门");

	set("long", @LONG
一走进巷子就会首先看到金府大门上的门环，原来这竟是用黄金铸成的，两旁
的铜狮子也上了层油光光的金漆，阳光一照，真可谓金光四射，门口有一个年纪
很大，满脸老奸巨滑样子的门房，皮笑肉不笑的坐在张藤椅上看着你。
LONG);
	
	set("type","house");
	set("exits",([
		"north":__DIR__"shilu4",
		"southeast":__DIR__"jinlin",
		"southwest":__DIR__"jinyuan",
	]) );
        set("objects", ([
                __DIR__"npc/guard":     1,
        ]));
	set("coor/x",50);
	set("coor/y",60);
	set("coor/z",0);
	setup();

}
int valid_leave(object me,string dir)
{
        if ( (dir=="southwest"||dir=="southeast") &&  present("jin guard", environment(me)))
        	return notify_fail("门房伸手拦住了你的去路，喝道：大帅现在休息，闲杂人等一律不见！\n");
        return ::valid_leave(me,dir);
}
