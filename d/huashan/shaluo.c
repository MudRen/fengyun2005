
inherit ROOM;

void create()
{
        set("short", "莎萝坪");
        set("long", @LONG
此处地势平坦，视野开阔。向东望，可观赏白云峰腰桃石和金龟戏玉蟾；西
北望是栩栩如生的灵芝石；东北望，有悬空而构的混元庵、小上方；向上望，华
山三峰雄伟挺拔，拴马桩一枝独秀。
LONG
        );
    set("exits", ([ 
  		"southwest" : __DIR__"shibapan",
  		"northwest" : __DIR__"wuli",
  		"southup" : __DIR__"cave",
		"east" : __DIR__"bieyuan",
	]));
	set("objects", ([
	]));  
    set("outdoors", "huashan");

	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

