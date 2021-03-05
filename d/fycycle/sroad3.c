inherit ROOM;
void create()
{
        set("short", "城南小路");
        set("long", @LONG
北边就是高大的风云城，一路上行人比肩，笙歌处处。小路的西南面是一个湖
泊，但见碧波如镜，垂柳拂水，景物之美，直如神仙境地。湖的对面红砖绿瓦，似
是富贵人家的庄园，长堤旁绿树成荫。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"fysouth",
  		"northwest": __DIR__"sroad2",
		"southwest": __DIR__"lake",
	]));
        set("outdoors", "fengyun");
	set("coor/x",-120);
	set("coor/y",-320);
	set("coor/z",0);
        setup();
}

