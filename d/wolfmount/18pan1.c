inherit ROOM;

void create()
{
	set("short", "十八盘");

	set("long", @LONG
山路崎岖盘绕难行，处处可见嶙峋的怪石奇岩，荆棘丛生，蔓藤环绕，在茫茫
的山雾中看去，更觉得阴森可怖。你辨了辨四下的地势，遂从乱山盘石间，往里穿
行。走出十八盘前方便是狼山第一险——狼牙岭！
LONG);

	set("type","road");
	set("exits",([
		"southup":__DIR__"wolfhill",
		"enter":__DIR__"tigerdelve",
		"westdown":__DIR__"18pan3",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/wenwen":1,
    	]) ); 
	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",-30);
	setup();
	replace_program(ROOM);
}
