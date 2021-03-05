
inherit ROOM;

void create()
{
	set("short", "剑泉");
	set("long", @LONG
苍松青叶之间，一条清泉从上山涓涓流淌下来，长年不断。传说中，天庭玄武
将军不慎把宝剑遗落于人间。落在武当山上，便是今天的剑泉。剑泉泉水甘美，过
往路人皆停驻于此。休息片刻，再行上山。但听泉水叮咚，松涛阵阵，你沉醉其中，
竟是忘了走路。
LONG
	);
	set("exits", ([
		"west" : __DIR__"sansongting",
	]));
	set("outdoors", "wudang");
        set("resource/water",1);
	set("liquid/name","剑泉水");
	set("liquid/type", "water");
	 set("objects", ([
                __DIR__"obj/pestle" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
