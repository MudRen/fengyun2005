
inherit ROOM;

void create()
{
        set("short", "练功室");
        set("long", @LONG
干干净净的墙上挂着一幅字画，上面写到“书山有路勤为径，学海无涯苦作舟。”
龙飞凤舞的字体，分明是庄主铁少所书。墙角堆着很多竹刀竹剑，地上打扫的一尘
不染，中间微微有些凹下，似乎是经常有人在此练功。入到此室之人，眼光无不为
墙上的[33m一刀一剑[32m所吸引住。
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"back_yard",
		]));
		
		set("item_desc", ([
			"一刀一剑":		"相思刀	销魂剑\n",
			"一刀":			"刀相思，人相依\n",
			"一剑":			"剑销魂，岁无痕\n",
		]));
		
       set("objects", ([
                __DIR__"obj/bsword" : 3,
                __DIR__"obj/bblade" : 4,
        ]) );

		set("coor/x",-10);
		set("coor/y",10);
		set("coor/z",0);
		setup();
}


void init()
{
	add_action("do_gets", "get");
}

int do_gets(string arg)
{
	object me, sword, blade;
	int ability;
	
	me = this_player();
	
	if(arg == "all")	{
		write("你太贪心了。\n");
		return 1;	
	}
	
	if (arg == "相思刀") {
		if (me->query("class")!="legend") {
			tell_object(me,"在别人庄园里做客，还是不要乱拿乱动的好。\n");
			return 1;
		}
		if (me->query_skill("dormancy",1) < 300
			|| me->query_skill("six-sense",1)<300) {
			tell_object(me,"雪蕊儿说：你的铁雪武功尚未成熟，取之有害无益。\n");
			return 1;
		}
		if (me->query("gender")=="男性") {
			tell_object(me,"雪蕊儿说：相思刀是给女弟子佩带的。\n");
			return 1;
		}
		seteuid(getuid());
		blade = new("/obj/specials/legend/mblade");
		if (blade->move(me)) {	
			ability = F_ABILITY->check_ability(me,"parry_add");
			blade->set("block_rate", 5 + ability/2);
			message_vision("$N轻轻地从墙上取下了相思刀。\n", me);
		} else
			destruct(blade);	
		return 1;
	}	
	
	if (arg == "销魂剑") {
		if (me->query("class")!="legend") {
			tell_object(me,"在别人庄园里做客，还是不要乱拿乱动的好。\n");
			return 1;
		}
		if (me->query_skill("dormancy",1) < 300
			|| me->query_skill("six-sense",1)<300) {
			tell_object(me,"铁少说：你的铁雪武功尚未成熟，取之有害无益。\n");
			return 1;
		}
		if (me->query("gender")=="女性") {
			tell_object(me,"铁少说：相思刀是给女弟子佩带的。\n");
			return 1;
		}
		seteuid(getuid());
		blade = new("/obj/specials/legend/msword");
		if (blade->move(me)) {	
			ability = F_ABILITY->check_ability(me,"parry_add");
			blade->set("block_rate", 5 + ability/2);
			message_vision("$N轻轻地从墙上取下了销魂剑。\n", me);
		} else
			destruct(blade);	
		return 1;
	}
	
	return 0;
			
}
