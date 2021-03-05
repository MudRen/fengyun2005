inherit ROOM;

void create()
{
    set("short", "洞道");
	set("long", @LONG
石壁上已经爬满了青苔，但还是明显看得出斧凿的痕迹，洞道曲折晦暗，而地
势却愈来愈开阔平坦，人行其中，一开始还得匍匐爬行，到得后来，却已是方圆数
丈距离。然而嶙峋的怪石，和曲折的洞道让道路更加难辨。
LONG);
	set("exits", ([
  		"east" : __DIR__"chiyoudao6",
  		"north" : __DIR__"chiyoudao7",
  		"south" : __DIR__"chiyoudao3",
		"west" : __DIR__"chiyoudao1",
	]));
	set("indoors","wolfmount");
	setup();
	replace_program(ROOM);
}

