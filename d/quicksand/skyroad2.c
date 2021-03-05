
inherit ROOM;

void create()
{
        set("short", "天涯路");
        set("long", @LONG
万里荒寒，连残阳都似已因寂寞而变了颜色，变成一种空虚而苍凉的灰白色。
漠漠黄沙，无边无际。似乎永远也走不到头，一眼望去，天连着黄沙，黄沙连着
天；人，也已在天涯。  
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"skyroad1",
  "northeast" : __DIR__"skyroad3",
]));
        set("outdoors", "quicksand");

	set("coor/x",-1130);
	set("coor/y",300);
	set("coor/z",0);
	setup();
}
