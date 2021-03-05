inherit ROOM;

void create()
{
	set("short", "卧室");

	set("long", @LONG
这里是郭大路和林太平的卧室。屋子不大，也没什么摆设，乱七八糟扔着些破
破烂烂的旧衣物，墙角布满了蜘蛛网，满屋子都是灰尘，呛的你不住咳嗽。燕七曾
笑言，这个屋子怕是只有郭林两人能忍受，别人怕是呆一会儿都要落荒而逃。
LONG);

	set("type","indoors");
	set("exits",([
		"east":__DIR__"grass4",
		"south":__DIR__"grass1",
	]) );

	set("objects",([
		__DIR__"npc/yan":1,
		__DIR__"npc/lin":1,
	]));

	set("coor/x",0);
	set("coor/y",240);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
