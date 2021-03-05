inherit ROOM;
void create()
{
        set("short", "太平镇");
        set("long", @LONG
太平镇原先只是个官家的驿站，来往的人多了，才逐渐开起了几个店铺。三年
前从山西忽然搬来了一个姓李的富豪，在镇边买下了一座庄园。镇上的男人多了，
自然就有了男人享乐的地方，红巷的鹦鹉楼远近闻名。不过即使这样，这仍不是个
很繁华的市镇，总共才住着八十三户人家。
LONG
        );
        set("exits", ([ 
		"northeast" : AREA_ZANGBEI"kunlun1",
		"east": __DIR__"yizhan",
		"southwest": __DIR__"mroad2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	
}
