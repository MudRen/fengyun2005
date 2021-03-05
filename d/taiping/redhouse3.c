inherit ROOM;
void create()
{
        set("short", "北耳房");
        set("long", @LONG
门外錾铜钩上悬着大红撒花软帘，才入屋中，只闻一阵香扑了脸来，竟不辨是
何气味，身子如在云端里一般。满屋中之物都耀眼争光的，使人头悬目眩。南窗下
是炕，炕上大红毡条，靠东边板壁立着一个锁子锦靠背与一个引枕，铺着金心绿闪
缎大坐褥。坐着个十四五岁的姑娘，打扮得花枝招展，却哭得像个泪人儿似的。
LONG
        );
        set("exits", ([ 
		"south": __DIR__"redhouse0",
	]));
        set("item_desc", ([
	
	 ]));
        set("objects", ([
        	__DIR__"npc/lady2":	1,
        	__DIR__"npc/mother":	1,
        	
        ]));
	set("coor/x",-80);
	set("coor/y",-40);
	set("coor/z",10);
	set("map","taiping");
	setup();
}

