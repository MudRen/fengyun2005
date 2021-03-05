inherit ROOM;

void create()
{
	set("short", "金府内宅");

	set("long", @LONG
这是间金府的厢房，门窗常年闭着，光线很昏暗。房里别无他物，只有中间放
着一张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG);
	set("type","indoors");
	set("exits",([
		"northeast":__DIR__"jinlin",
		"northwest":__DIR__"jinyuan",
	]) );
	set("coor/x",60);
	set("coor/y",40);
	set("coor/z",0);
	set("objects" , ([
		__DIR__"npc/guard2":1,
		__DIR__"npc/guard2a":1,
	    __DIR__"obj/bed" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
