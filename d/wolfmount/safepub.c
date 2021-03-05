inherit ROOM;

void create()
{
	set("short", "太平客栈");

	set("long", @LONG
狼山自然一点也不太平，唯一能让你喘口气的地方就只有半山腰这家太平客栈
了。除了歪歪斜斜挂在门口的一块大招牌，上面写着“太平客栈”四个大字，别的
地方就没有一点客栈的样子。只是一间茅草搭的破屋子，里面连一张桌子一把椅子
也没有，通向后院的竹门虚掩着。
LONG);

	set("type","house");
	set("exits",([
        "northeast":__DIR__"littlesky1",
		"south":__DIR__"pubyard",
		"northwest":__DIR__"gully",
	]) );
    set("valid_startroom", 1);
       set("indoors", "wolfmount");
        set("no_magic",1);
        set("no_fight",1);
	set("objects",([
     		__DIR__"npc/shengyi":1,
    	]) ); 
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
    	setup();
	replace_program(ROOM);
}
