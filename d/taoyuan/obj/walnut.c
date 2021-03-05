inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("小青核桃", ({ "walnut", "he tao", "hetao" }) );
        set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "这是一个青色的核桃，也不知道成熟没有。你也许想剥（ＰＥＥＬ）开来看看。\n");
        set("unit", "个"); 
        set("value", 1);
    	set("peeled", 1);
    }
    ::init_item();
}

void init () {
	if( this_player() == environment()) {
		add_action("do_eat", "eat");
		add_action("do_peel", "peel");
	}
}

int do_eat(string arg)
{
    object walnut, me;
    
    me = this_player();    
    if (!arg || arg != "walnut" && arg != "小青核桃" && arg != "hetao") return 0; 	
   	if (query("peeled")) {
	   	message("vision", me->name() + "抓起一个带皮的青核桃就咬，马上吐了出来，被涩得直伸舌头。\n", 
   				environment(me), me);
   		write("哇！什么怪味！又涩又苦！\n");
   		write("你连忙吐了出来，可嘴里还是涩得难受。 \n");
   		remove_call_out("pig_mouth");
		call_out("pig_mouth", 20, me);
	} else {
		message("vision",me->name() + "拿出一个核桃仁放到嘴里！\n", environment(me), me);
   		write("你拿起核桃仁尝了尝，又甜又凉，真是好极了！ \n");
    	me->add("food", 2);
		destruct(this_object());
	}
    return 1;
}

void pig_mouth(object me)
{
	tell_object(me, "可能是带皮的核桃有毒吧，你两腮又胀又痛，肿了起来。\n");
	message("vison", "不知道什么原因" + me->name() + "的嘴巴慢慢肿了起来，"
			+ "不一会嘴巴就肿得象个小猪嘴。\n", environment(me), me); 
}

int do_peel(string arg)
{
	object walnut, me, weapon, obj;
	
	if (!arg || arg != "walnut" && arg != "小青核桃" && arg != "hetao") {
		write("你要剥什么？\n");
		return 1;
	}
	me = this_player();
	weapon = me->query_temp("weapon");
	if (query("peeled")) {
		if(!weapon) {
    		write("你手上没有合适的锐器，用手是剥不来青核桃的。\n");
   		} else {
			if(weapon->query("flag") & 4) {
				message_vision("$N小心地削掉青色的外果皮，切开果壳，取出了核桃仁。 \n", me);
				set("peeled", 0);
				set_name("核桃仁", ({"walnut", "peeled walnut"}) );
				set("long", "白白嫩嫩的核桃仁。\n");
			} else {
				write("用这个是没办法削核桃皮的，换一个试试。\n");
			}
		}
	return 1;
	}
	return 0;
}