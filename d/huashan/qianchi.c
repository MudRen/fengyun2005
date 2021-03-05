
inherit ROOM;

void create()
{
        set("short", "千尺幢");
        set("long", @LONG
面前一石崖似被利斧从中劈开形成一个裂缝，缝宽仅三尺，直立七十度，后人
沿隙凿拓成路，有石阶370级。阶宽仅可容半足，踏足石阶之上，仰视一线天开，
俯视若临深井。
LONG
        );
    set("exits", ([ 
  		"eastup" : __DIR__"canglong",
  		"northdown" : __DIR__"huixin",
	]));
   
    set("outdoors", "huashan");
    set("objects", ([
		__DIR__"npc/monkey2" : 1,
	]));  

	set("coor/x",-15);
	set("coor/y",-50);
	set("coor/z",20);
	setup();
    replace_program(ROOM);
}

