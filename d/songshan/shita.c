// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "嵩岳寺塔");
        set("long", @LONG
在嵩山南麓，上来便可见这座高塔，她是最古老的佛塔，俗称北魏大塔，塔西
高岭上大片平坦的土地，从地上随处可见砖砌地下水道，铺砖地面和造型古雅的花
纹砖和瓦当。此塔平面外廓正十二边形，中央塔室为正八面形。全塔由基台，塔身，
密檐，宝刹构成融合中印风格，造型之奇，难度之高是绝无仅有的。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"fawang", 
  "east" : __DIR__"huishan",
  "southwest" : __DIR__"shuyuan",
]));
        set("objects", ([
                __DIR__"npc/amao" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
