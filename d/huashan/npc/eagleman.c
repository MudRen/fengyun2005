#include <ansi.h>
inherit NPC;
int wandao(object me);
int do_killqing(object me);
void create()
{
	set_name("金鹰老人", ({ "eagle man"}) );
	set("gender", "男性" );
	set("age", 55);
	
	set("long", @LONG
这个人只有三尺多高，三尺长的金袍子穿在他身上，已经拖下了地。他的胡 
子比这件袍子更长，黄金铸成的剑比胡子还长。 
LONG
);
    
    	set("combat_exp", 10000000);
	set("attitude", "friendly");
	set("inquiry_wangyou", 0);
	
	set_skill("dodge", 250);
	set_skill("move", 200);
	set_skill("parry", 250);
	set_skill("sword", 200);
	set_skill("doomsword", 200);
	set_skill("doomsteps", 200);
	set_skill("unarmed",200);
	set_skill("doomstrike",200);
	map_skill("unarmed","doomstrike");
	map_skill("sword", "doomsword");
	map_skill("parry", "doomsword");
	map_skill("move", "doomsteps");
	map_skill("dodge", "doomsteps");
	
	set("str", 80);
	set("require_rescue", 0);
	set("reset", 1);
	setup();
	carry_object("/obj/armor/cloth",
		([ 	"name" : HIY"金袍子"NOR,
			"long" : "一件三尺长用金丝织成的袍子",
			"value": 10000,
			"weight": 3000]) 
		 )->wear();
}


int wangyou(object me){
	object obj;
	if(interactive(me) && environment(me) == environment(this_object())) {
		message_vision("\n$N冷冷地看了$n一眼：“你这样的凡人是不配得到忘忧草的，它只能给你带来烦恼。”\n",
				this_object(), me); 
			message_vision("$N接着道：“你还是把它交给我吧。（ａｃｃｅｐｔ　ｙｅｓ／ｎｏ）\n", this_object());
		add_action("do_accept", "accept");
		set("inquiry_wangyou", 1);
		call_out("remove_inquiry", 15, me);
		add_action("do_rescue", "rescue");
	} else {
		environment(this_object())->do_leavee();
		environment(this_object())->do_leave();
	}
}

int remove_inquiry(object me){
	object obj;
	if(!me||!interactive(me) || environment(me) != environment(this_object())|| !this_object()) {
		environment(this_object())->do_leave();
		environment(this_object())->do_leavee();
	}
	obj = present("qing qing", environment(this_object()));
	if(objectp(obj)){
		message_vision("$N冷笑道：“既然你舍不得...”，$N的眼光飘向青青。\n", this_object());
	}
	set("inquiry_wangyou", 0);
	wandao(me);
}


int do_accept(string arg){
	object me, grass;
	me = this_player();
	remove_call_out("remove_inquiry");
	if(!arg || (arg != "yes" && arg != "no")) {
		return 0;
	}
	if(!query("inquiry_wangyou")) {
		return 0;
	}
	if(me->is_busy() || me->is_fighting()) {
		return notify_fail("你正在忙！\n");
	}
	grass = present("wang you", me);
	if(!objectp(grass)) {
		message_vision("$N阴笑一声：“想骗我？”\n", this_object());
		this_object()->kill_ob(me);
		me->kill_ob(this_object());
		return 0;
	}
	if(arg == "yes") 
	{
		set("inquiry_wangyou", 0);
		message_vision(BLU"$N慑于$n的威势，又迷于诱惑，把忘忧草交给$n。\n"NOR, me, this_object());  
     		message_vision("$N哈哈大笑，接过忘忧草。\n", this_object()); 
        	destruct(grass);

		environment(this_object())->do_leaveq();
		environment(this_object())->do_leavee();
		
	}
	if(arg == "no") {
		set("inquiry_wangyou", 0);
		message_vision(YEL"$N直视老人的目光：“忘忧草是我为青青姑娘摘的，她指点在先，我摘取在后。\n"NOR, me);
     		message_vision(YEL"如果前辈有用，何不自己动手？”\n"NOR, me);
     		message_vision(HIY"\n$N哼了一声，“要我动手，你还不配！”\n"NOR, this_object()); 

//     	call_out("wandao", 3, me); 
		wandao(me);
	}	
	return 1;
}

int wandao(object me){
	object obj, grass;
	if(obj = present("qing qing", environment(this_object()))) {
		message_vision("\n$N盯着青青腰带上的那柄刀。那柄青青的、弯弯的刀。\n", this_object());
		message_vision(HIW"$N的弯刀在圆月下闪动着银光。\n"NOR, obj);
 		obj->xiaolou(me);
	} else {
		grass = present("wang you", me);
		if(objectp(grass)){
			message_vision("\n$N只觉得眼前人影一闪，$n手中已然多了一株碧绿的小草。\n", me, this_object());
			destruct(grass);
		}
		environment(this_object())->do_leavee();
	}
	return 1;
}


int wf(object me) {
	if(!interactive(me) || environment(me) != environment(this_object())) {
		environment(this_object())->do_leave();
		environment(this_object())->do_leavee();
	} else {
		call_out("wandao_found", 2, me);
	}
	return 1;
}

int wandao_found(object me){
	if(!interactive(me) || environment(me) != environment(this_object())) {
		environment(this_object())->do_leave();
		environment(this_object())->do_leavee();
	}	
//	message_vision("\n$N忽然仰天而笑，狂笑：“果然是这把刀，老天有眼，总算叫我找到了这把刀！”\n", 
//			this_object());
//	message_vision("\n狂笑声中，剑已出鞘。\n", this_object()); 
	message_vision(HIY"\n$N突然出剑。就算闪电都没有如此亮，如此快！\n"NOR,
			this_object());
	message_vision(HIR"剑光一闪，青青的人就倒了下来，就像一瓣鲜花忽然枯萎，坠下了花蒂。\n"NOR, this_object()); 
	message_vision(RED"\n$N如巨鹰又一剑下击，这一剑绝对是致命的一剑，准确、狠毒，迅速，无情。\n"NOR,
			this_object()); 
	tell_object(me, "青青缓缓倒下，那曾经柔和明亮的眼睛暗淡下去，似乎已经失去了抵抗的力量。
（ｒｅｓｃｕｅ　ｑｉｎｇ）\n");
//	tell_object(me, "\n你大惊失色，想冲上去救她。（ｒｅｓｃｕｅ　ｑｉｎｇｑｉｎｇ）\n"); 
	me->set_temp("rescue_time", time());
// 	add_action("do_rescue", "rescue");	
	set("require_rescue", 1);
	call_out("do_killqing", 15, me);
	return 1;
}

int do_rescue(string arg){
	object me, obj;
	int i;
	me = this_player();
	if(!interactive(me) || environment(me) != environment(this_object())) {
		environment(this_object())->do_leave();
		environment(this_object())->do_leavee();
		return 1;
	}
	if(!obj = present("qing qing", environment(this_object()))) {
		environment(this_object())->do_leavee();
		return 1;
	}	
	if(!query("require_rescue")) {
		return 0;
	}
	if(!arg || arg != "qing") {
		return notify_fail("你要救谁？\n");
	} else {
		remove_call_out("do_killqing");
		if(time() - (int)me->query_temp("rescue_time") < 10) {
			message_vision("\n看着这一剑飞落，$N忽然扑过去，扑在青青的身上。剑光一闪，刺入了$N的背。\n", me);
			tell_object(me, WHT"\n你并不觉得痛苦。你只觉得很冷，只觉得有种不可抗拒的寒意，忽然穿入了你的背，
穿入骨髓。\n"NOR); 
			obj->do_killeagle(me);

		} else {
			tell_object(me, "你犹豫一下，青青是个陌生的女子，而这老人绝对是个杀神。值得冒生命之险吗？\n");
			tell_object(me, "你突觉心里一寒，被金鹰老人剑气所伤。\n");
			message("vision", "          剑气扫过\n", environment(me), me);
			me->unconcious();  
			do_killqing(me);
		}
	}
	return 1;
}

int do_killqing(object me){
	object obj, blade;
	obj = present("qing qing", environment(this_object()));
	if(objectp(obj)) {
		message_vision("\n剑光没入$N的胸前，你将再也不会见到那样柔那样美的眼波了。\n", obj);
		blade = present("moonblade", obj);
		message_vision("你根本没有看清$N的动作，不知怎的弯刀却已落入$P手中。\n", this_object());
		message_vision(HIW"银色的刀鞘在月光下闪着刺眼的光，似乎在嘲笑这无情的世界。\n"NOR,
				this_object());
		destruct(blade);
		obj->die();
		environment(this_object())->do_leavee();
	} else {
		environment(this_object())->do_leavee();
	}
	return 1;
}

