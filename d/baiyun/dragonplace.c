//Sinny@fengyun 2003 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
    set("short", "龙台");
    set("long", @LONG
路旁的白石座上千百个清晰的螭首的投影，犹如一幅色彩明快的水彩画。雨天，
三层螭首的千龙吐水，胜似喷泉，更蔚为奇观。一个白衣狂客踏水放歌：
                           三    千
                           尺    载
                           青    壮
                           锋    志
LONG
    );
    set("exits", 
      ([ 
	"southup" : __DIR__"yanchilou",
	"northdown" : __DIR__"feixianting",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/jiandan" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-30);
    set("coor/y",-65);
    set("coor/z",10);
    setup();
    replace_program(ROOM);
}
