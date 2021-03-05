// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
山路一转弯，出现了一个小山坳，此处三面环山，满眼尽是怀抱不拢的古柏，
向西看天都峰已然在望。一条残破的小石板路从树林中穿过，顺山势向上没入树林
之中，山的半腰似有一座小寺庙。
LONG
        );
	set("exits", ([ 
  		"northup" : __DIR__"banshan",
  		"westup" : __DIR__"guanyin",
  		"south" : __DIR__"mroad2",
	]));
    
    set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
