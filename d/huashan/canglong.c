
inherit ROOM;
void fall(object me);
void create()
{
        set("short", "苍龙岭");
        set("long", @LONG
刀形的山脊呈苍黑色，石路长约百米，宽不足三尺，两侧深渊千尺，每当山风
吹过、云雾飘来，上面行人似站云端，又似乘风飞去，让人不由得心旌神摇，惊险
异常。有诗道：“岭下望岭上，夭矫蜿蜓飞。背无一仞阔，旁有万丈垂。 循背匍匐
行，始敢纵横施。惊魂及坠魄，往往随风吹。 ”
LONG
        );
    set("exits", ([
        "westdown" : __DIR__"qianchi", 
  		"northup" : __DIR__"yuntai",
  		"southup" : __DIR__"yunv",
	    "eastdown" : __DIR__"xiaodao",
	]));
	set("objects", ([
		__DIR__"npc/gao" : 1,
	]));   
    set("outdoors", "huashan");

	set("coor/x",-12);
	set("coor/y",-50);
	set("coor/z",30);
	setup();
}

void init(){
	object me;
	string weather;
	
	me = this_player();
	if (!userp(me))	return;
		
	weather = NATURE_D->get_weather();
	
	if(weather == "阵风" && !random(200)) {
		message_vision("一阵风吹过，$N身形一晃，伴随着一声惊叫，$N滚落山崖。\n", me);
		fall(me);
	} else if(weather == "狂风" && !random(100)){
		message_vision("一阵狂风吹过，$N身形一晃，伴随着一声惊叫，$N滚落山崖。\n", me);
		fall(me);
	} else if((weather == "雪" || weather == "大雪") && !random(80)) {
		tell_object(me, "你只觉得脚下一滑，身子陡然滑向了一边，你不由得发出了一声惊叫。\n");
		message("vision", "只听一声惊叫，$N滚下了山岭。\n", environment(me), me);
		fall(me);
	} else if(!random(600)) {
		message_vision("$N一脚落空，滚下了山岭。\n", me);
		fall(me);
	}
}

void fall(object me){
	object room;
	if (!me)	return;
		
	room = find_object(__DIR__"yadi");
	if(!objectp(room)){
		room = load_object(__DIR__"yadi");
	}
	me->move(room);
	message("vision", "只见" + me->name() + "从空中坠落，“扑通”一声落到了地上。\n", environment(me), me);
	if ( random(2) ) me->unconcious();
}
