
inherit ROOM;

void create()
{
	set("short", "紫霄宫");
	set("long", @LONG
殿顶由四根八丈高的红柱撑著，地板则是由白玉石铺成。左右墙上挂著几幅字
画，正面的墙上高高地挂著一块金匾，上书“紫霄宫”三字。匾下是一张供台，一
尊太上老君像正坐其中。像前摆著各式水果和两具烛台。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"wudang1",
	]));
	set("objects", ([ 
		__DIR__"npc/master" : 1,
		__DIR__"npc/taoist" : 1,
	]));

	set("item_desc", ([
	"神像":"一尊太上老君像，神像后是一垂布幔。\n",
	"statue":"一尊太上老君像，神像后是一垂布幔。\n",
	"布幔":"布幔上染着淡淡的幽香，其后竟有一条窄窄的径道，看起来非人所能挤进。\n",
	]) );

        set("valid_startroom", 1);
	set("coor/x",15);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
replace_program(ROOM);

}
