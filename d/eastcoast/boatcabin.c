// seaside.c
inherit ROOM;
void create()
{
        set("short", "船舱");
        set("long", @LONG
艳丽的阳光，正照在精美的雕花窗户上。船舱正中是一张床，一张宽大，柔软，
非常华丽舒服的床，紫缎被褥上睡着一个完全赤裸着的女孩，细弱的腰肢，柔软修
长的腿，一双乳房，看来就像是早春的花蕾，娇弱无助，楚楚动人。床边的檀木几
上放着生虾片夹着的饭团和一杯酒。
LONG
        );
        set("exits", ([ 
		"out":  __DIR__"boatbow",
	]));
        set("objects", ([
        AREA_TAIPING"npc/longwang" : 1,
        AREA_TAIPING"npc/longnu": 1,
        AREA_TAIPING"obj/table": 1,
                        ]) );

        set("item_desc", ([
		"床": "一张宽大，柔软，非常华丽舒服的床。\n",
		"bed": "一张宽大，柔软，非常华丽舒服的床。\n",
	 ]));
	set("coor/x",1030);
	set("coor/y",30);
	set("coor/z",10);
	setup();
}



void reset()
{
	object table,item1;
        ::reset();
        table = present("table", this_object());
        
        if (!present("rice",table)){
        	item1 = new(AREA_TAIPING"obj/ricecake");
        	item1->move(table);
        	}
}