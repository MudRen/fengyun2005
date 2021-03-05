// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
山路到了这里逐渐平缓，然而路面不足三尺宽，一边是百尺深渊，一边是万丈
峭壁。探头看，山壁有如刀削，无一可着力之处，一道小溪在下面缓缓流过；向上
看，陡峭的崖壁上生长着一簇簇不知名的植物，有些还开着淡淡的小花。
LONG
        );
	set("exits", ([ 
  		"eastdown" : __DIR__"qingluan",
  		"north" : __DIR__"mroad3",
	]));
    
    set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}
