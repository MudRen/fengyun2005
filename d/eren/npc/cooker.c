#include <ansi.h>
inherit NPC;
inherit INQUIRY_MSG;

void create()
{
        set_name("厨师", ({ "chef" }) );
        set("gender", "男性" );
        set("age", 43);
        set("long", "一个满脸红光的大厨。\n");
        
        set("combat_exp", 1000000);
        
	set("attitude", "friendly");
        
        set_temp("apply/attack", 150);
	set_temp("apply/dodge",150);
  
  
  	set("inquiry", ([
        	"原料" : "烧菜的原料不够，哈老板正急着找人帮忙呢。",
        	"鸟舌": "知道我还要你帮忙？",
   			"烤山猪肉": "知道我还要你帮忙？",
   			"沙虫肝": "知道我还要你帮忙？",
   			"熊掌": "知道我还要你帮忙？",
   	]));      
        set("chat_chance", 1);
        set("chat_msg", ({
			"大厨汗流浃背地忙着烧菜，香味四溢。。。\n",
			"大厨叹口气说：原料不全，巧妇难为无米之炊啊。\n",
        }) );
        setup();
		carry_object(__DIR__"obj/apron")->wear();
}


int accept_object(object me, object obj){
	int ok;
	string meal;
	object entry;
	
	if (REWARD_D->riddle_check(me,"山珍海味")!=1 
		&& !REWARD_D->check_m_success(me,"山珍海味")) {
		command("say 这是什么东西？我只烧哈老板要的菜。");
		return 0;
	}
	
	switch (obj->query("name"))	{
		case "烤山猪肉":		tell_object(me,"大厨说：不错、不错，上好的烤山猪肉！\n");
								meal = __DIR__"obj/entry1";
								ok = 1; 
								break;
		case "熊掌":			tell_object(me,"大厨说：熊掌倒是真的，不过不知道已经放了多少年了，早风干了。\n");
								break;
		case YEL"熊掌"NOR:		
								if (!obj->query("winter"))
								{
									tell_object(me,"大厨说：这熊掌怎么瘦瘦小小像狗爪，哪里能够做菜。\n");
								} else {
									tell_object(me,"大厨说：不错、不错，上好的熊掌！\n");
									meal = __DIR__"obj/entry3";
									ok = 2;
								}
								break;
		case "小山雀舌":		tell_object(me,"大厨说：这鸟舌又粗又硬，是鸭子的吧？\n");
								break;
		case "百灵鸟舌":		tell_object(me,"大厨说：不错，又细又嫩，上好的鸟舌！\n");
								meal = __DIR__"obj/entry2";
								ok = 3;
								break;
		}
		
		if (!ok)	return 0;
		
		tell_object(me, YEL"大厨回身转到灶台前忙开了，一顿饭的功夫便端出个盘子给你。
大厨说：拿去给哈老板评点评点！\n"NOR); 
		
		entry= new(meal);
		if (!entry) {
			command("say OOPS, BUGS!");
			return 0;
		}
		
		entry->move(me);
		return 1;
		
}