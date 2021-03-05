inherit ROOM;
void create()
{
        set("short", "葡萄沟");
        set("long", @LONG
这里水渠纵横，终日川流着天山雪水。沟的两侧山坡上虽寸草不生，但沟里却
绿树成荫，葡萄架成片，潺潺流水，座座草房，一派旖旎风光进入葡萄沟，犹如进
入一个清凉世界。只见那近百株碗口般粗的葡萄藤爬在架子上，爬满走道的上空，
长着茂密的叶子和汉白玉般的串串葡萄伸手可及。
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"emin",
  "eastup" : __DIR__"huoyan",
]));
        set("objects", ([
        __DIR__"npc/waiter2" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
