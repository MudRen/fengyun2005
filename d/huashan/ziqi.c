
inherit ROOM;

string flower();
void create()
{
        set("short", "紫气台");
        set("long", @LONG
这里称台却不在山顶，半山腰出现一块平地，四周巨大的古柏着天蔽日。平地
上原建有老君庙，但荒废已久，现在只剩下残墙断瓦，杂草衍生，只有一棵腊梅，
依旧枝叶茂密，每至岁寒，含苞怒放，星星点点黄如蜡塑，香飘十里。
LONG
        );
    set("exits", ([ 
  		"northup" : __DIR__"chaoyang",
	    "southwest" : __DIR__"shanlu",
	]));
  	set("objects", ([
  		__DIR__"obj/wall" : 1,	
  		__DIR__"npc/girl1" : 1,
  	])); 
    set("item_desc", ([
    	"腊梅" : (: flower :),
    	"tree" : (: flower :), 
    ]));
    set("flower_amount", 5);
    set("outdoors", "huashan");

	set("coor/x",-4);
	set("coor/y",-56);
	set("coor/z",30);
	setup();
}

string flower(){
	object me;
	int i, j;
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 4) {
		tell_object(me, "腊梅含苞怒放，黄色的腊梅花衬托在白雪中是那样的清雅，空气中充满腊梅的清香。\n");
		add_action("do_pick", "pick");
	} else {
		tell_object(me, "腊梅数枝叶茂密。\n");
	}		
	return "";
}

int do_pick(string arg){
	object me, flower;
	me = this_player();
	if(!arg || (arg != "flower" && arg != "腊梅")) {
		return 0;
	}
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("你正在忙！\n");
	}
	if(query("flower_amount") > 0) {
		message_vision("$N探手摘了一枝腊梅花。\n", me);	
		flower = new(__DIR__"obj/wintersweet");
		flower->move(me);
		add("flower_amount", -1);
	} else {
		return notify_fail("腊梅没有了。\n");
	}
	return 1;
}

void reset(){
	::reset();
	set("flower_amount", 5);
}
