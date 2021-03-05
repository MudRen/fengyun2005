#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "听风阁");

	set("long", @LONG
绣槛雕栏，绿窗朱户，屋中布置得相当考究，屋中点了支檀香，香味混着飘进
屋中的紫藤花香，不由让人心旷神怡。青石地板上斜斜躺着个人，好象被制住了手
脚，一把锋利的长剑丢在一旁。
LONG);

		set("type","indoors");
		set("exits",([
			"east":__DIR__"fyyard",
		]) );
        set("indoors", "chenxiang");
		set("coor/x",10);
		set("coor/y",60);
		set("coor/z",0);
		set("objects",([
     		__DIR__"npc/bai": 1,
     		__DIR__"obj/floor": 1,
    	]) );
		setup();
}


int do_answer(string arg)
{
	object *inv;
	int i;
	int div;
	object me,bai;
	object room,floor;

	me = this_player();
	room = this_object();
	bai = present("bai yujing", room);
	floor = present ("stone floor", room);
	
	div =0;
	inv = all_inventory(floor);
        for(i=0; i<sizeof(inv); i++)
        	if(inv[i]->query("baiyujing"))
        	{
			div = 1;
			destruct(inv[i]);
        	}

        if( arg != "love" &&  arg != "hate") 
                return notify_fail("你要回答什么？？\n");
        if( arg == "love" ) 
        {
                message_vision( HIR "\n$N想也不想立刻答道：那么动人的微笑，真甜、真美，只有真心
相爱的人才会笑的那么甜，袁姑娘是刻骨铭心地爱着你的呀。\n"NOR, me);
		if (div)
			call_out("goodresult",2,bai,me,room);
		else
			call_out("midresult",2,bai,me,room);
        }
        else if( arg == "hate" )
        {
            	message_vision( HIB "\n$N迟疑了半天，摇摇头轻声道：红颜祸水，怎可轻信？\n"NOR, me);
        	call_out("badresult",2,bai,me,room);
        }
	return 1;
}

int gethim(object target,object me,object room)
{
	if(!target || !me ) return 1;
	if(environment(me) == room)
	{
        	message_vision("$N一句话不说，匆匆忙忙地离开了。\n",target);
        	target->move(this_object());
        	message_vision("$N走了进来。\n",target);
		return 1;
	}
	return 1;
}

void goodresult(object bai,object me,object room)
{
	object yuan,wei;
	yuan = find_real_living("yuan zixia");
	wei = find_real_living("wei tianying");
	
	if (yuan && wei && bai)
	{
		wei->remove_all_killer();
		call_out("gethim",0,wei,me,room);
		call_out("gethim",0,yuan,me,room);
		call_out("event",4,wei,yuan,bai,me,1);
		me->start_busy(4);
		return;
	}
	return;
}

void event(object wei,object yuan,object bai,object me,int i)
{
	switch(i)
	{
	case 1:	
        	message_vision( HIY "\n$N望了望白玉京和$n，眨了眨眼道：真抱歉，卫二哥要我动手杀了你。\n\n"NOR,yuan,me);
		break;
	case 2:
        	message_vision( GRN "$N向前一纵，脚尖轻挑，长生剑便犹如灵蛇般飞向$n。\n\n"NOR, yuan,bai);
		break;
	case 3:
        	message_vision( HIC "$N长啸一声，犹如鹰击长空，动身跃起，凌空一把抄起长生剑。\n\n$N瞬息之间，宛如行云流水连刺三剑。\n\n剑光似星雨银河。\n\n星光散，血光现。\n\n\n"NOR, bai,wei);
		wei->die();
        	message_vision( HIY "$N向$n拱手笑道：不识庐山真面目，只缘身在此山中，多谢这位" + RANK_D->query_respect(me)+ "\n指点迷津！\n\n"NOR, bai,me);
			
        	REWARD_D->riddle_done( me, "天上白玉京", 100, 1);
        	
        	message_vision( HIY "$N轻舒猿臂，揽住$n的杨柳细腰，相视一笑，飘然而去。\n"NOR, bai,yuan);
		if (!REWARD_D->imbue_check( me, "天上白玉京"))
				call_out("imbue_event2", 3, me);
		me->stop_busy();
/*		if(!me->query("imbue/yuan")){
				call_out("imbue_event2", 3, me);
		}*/
		destruct(yuan);
		destruct(bai);
		return;
	}
	i=i+1;
	call_out("event",2,wei,yuan,bai,me,i);
}

void badresult(object bai,object me,object room)
{
	object yuan,wei;
	yuan = find_real_living("yuan zixia");
	wei = find_real_living("wei tianying");
	
	if (yuan && wei && bai)
	{
		wei->remove_all_killer();
		call_out("gethim",0,wei,me,room);
		call_out("gethim",0,yuan,me,room);
		call_out("badevent",2,wei,yuan,bai,me,1);
		me->start_busy(4);
		return;
	}
	return;
}

void badevent(object wei,object yuan,object bai,object me,int i)
{
	switch(i)
	{
	case 1:	
        	message_vision( HIB "$N狞笑道：就让你们到黄泉相会吧。\n$N手中长刀有如雷霆霹雳砍向$n。\n\n"NOR,wei,bai);
		break;
	case 2:
        	message_vision( HIB "$N深情地看了$n一眼，悲鸣一声，惨然一笑扑向刀锋。\n血光飞溅，$N顿时香销玉陨。。。\n\n"NOR, yuan,bai);
		yuan->die();
		break;
	case 3:
        	message_vision( HIB "$N接着一刀劈向$n。\n$n仰天悲嘶一声。。\n\n"NOR,wei,bai);
        	message_vision( HIB "血泊中的袁紫霞再也无法绽放那美丽的笑容，$N看着院中飞散飘落着带血的紫藤花。。\n\n$N倒在了血泊中，挣扎着爬向袁紫霞的尸身。\n\n一寸、一寸。。$N挪动着身体。。石板上拖了一道触目惊心的血痕。。\n\n$N深情地望着袁紫霞。。头一歪。。\n\n\n"NOR, bai);
		bai->die();
		
        REWARD_D->riddle_done( me, "天上白玉京", 100, 3);
        	message_vision( HIR "$N嘿嘿冷笑着：在场的一个也不能活！\n"NOR, wei);
		wei->kill_ob(me);
		me->kill_ob(wei);
		me->stop_busy();
		if (!REWARD_D->imbue_check( me, "天上白玉京"))
				call_out("imbue_event", 5, me);
		return;
	}
	i=i+1;
	call_out("badevent",2,wei,yuan,bai,me,i);
}

void midresult(object bai,object me,object room)
{
	object yuan,wei;
	yuan = find_real_living("yuan zixia");
	wei = find_real_living("wei tianying");
	
	if (yuan && wei && bai)
	{
		wei->remove_all_killer();
		call_out("gethim",0,wei,me,room);
		call_out("gethim",0,yuan,me,room);
		call_out("midevent",2,wei,yuan,bai,me,1);
		me->start_busy(4);
		return;
	}
	return;
}

void midevent(object wei,object yuan,object bai,object me,int i){
	object petal, ob;
	switch(i)
	{
	case 1:	
        	message_vision( HIW "$N向$n眨了眨眼道：真抱歉，卫二哥要我动手杀了你。\n\n"NOR,yuan,bai);
		break;
	case 2:
        	message_vision( HIW "$N纵身跃到$n身边，刚想解开$n的穴道。\n\n"NOR, yuan,bai);
		break;
	case 3:
        	message_vision( HIW "$N似乎早就看出$n企图，长刀闪着诡异的光芒划过$n的胸膛。\n\n$n伸出手想拉紧白玉京的手，但终是没能够到。。。\n\n"NOR, wei,yuan);
		yuan->die();
	case 4:
        	message_vision( HIW "$N刀锋一转，顺势捅入$n的胸膛。\n血光飞溅，$n挣扎爬向袁紫霞的尸身，但。。\n\n"NOR, wei,bai);
		bai->die();
		
		REWARD_D->riddle_done( me, "天上白玉京", 100, 2);
        	petal = new(__DIR__"obj/petal");
		ob = present("floor", this_object());
		if(objectp(petal)) {
			petal->move(ob);
		}
        	message_vision(MAG"\n风儿轻轻吹过，一瓣带血的紫藤花瓣儿静静飘落在地板上。\n"NOR, me);
        	message_vision( HIR "$N看着血泊中的尸体，不禁狂笑起来。\n"NOR, wei);
		wei->kill_ob(me);
		me->kill_ob(wei);
		me->stop_busy();
		if (!REWARD_D->imbue_check( me, "天上白玉京"))
			call_out("imbue_event", 5, me);
		return;
	}
	call_out("midevent",2,wei,yuan,bai,me,i+1);
}

void answer_notify(object bai, int i)
{
	add_action("do_answer","answer");
}


void imbue_event(object me){
	object weapon/*, petal, ob*/, *inv, obj;
//	string prop;
	int i;
	mapping data;
	if(!interactive(me) || environment(me) != this_object()) {
		return 0;
	}
	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	if(!objectp(weapon)){
		if(!objectp(obj)) {
			message_vision(MAG"\n风儿轻轻吹过，一瓣带血的紫藤花瓣儿静静飘落在地板上。\n"NOR, me);
		} else {
			message_vision(MAG"\n风儿轻轻吹过，一瓣带血的紫藤花瓣儿静静飘落在$N的" + obj->name() + MAG"上。。。\n"NOR,
					me);	
			message_vision(MAG"花瓣儿悄悄滑落，" + obj->name() + MAG"依然如旧。\n"NOR, me);
		}
	}else{
		message_vision(MAG"\n风儿轻轻吹过，一瓣带血的紫藤花瓣儿静静飘落在$N的" + weapon->name() + MAG"上。。。\n"NOR,
				me);
		message_vision(MAG"花瓣儿隐去，一丝极淡极淡的血痕隐隐浮现在$N的" +
				weapon->name() + MAG"上，又迅速消去。\n"NOR, me);
	}
	data = ([
		"name":		"天上白玉京",
		"target":	me,
		"att_3":	"random",
		"att_3c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);	
	return ;
}


void imbue_event2(object me){
	object weapon/*, ob*/, *inv, obj;
//	string prop;
	int i;
	mapping data;
	if(!interactive(me) || environment(me) != this_object()) {
		return 0;
	}

	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	if(!objectp(weapon)){
		if(!objectp(obj)) {
			message_vision(MAG"\n两个紧紧相依的人影渐渐远去，风儿轻快的吹过，藤花瓣儿在微风中飘舞。\n"NOR, me);
		} else {
			message_vision(MAG"\n两个紧紧相依的人影渐渐远去，藤花瓣儿在微风中飘舞。一瓣紫藤花瓣儿静静飘落在$N的" 
					+ obj->name() + MAG"上。。。\n"NOR, me);	
			message_vision(MAG"花瓣儿悄悄滑落，" + obj->name() + MAG"依然如旧。\n"NOR, me);
		}
	}else{
		message_vision(MAG"\n两个紧紧相依的人影渐渐远去，藤花瓣儿在微风中轻舞。一瓣紫藤花瓣儿静静\n飘落在$N的" 
				+ weapon->name() + MAG"上。。。\n"NOR, me);
		message_vision(MAG"花瓣儿隐去，一丝极淡极淡的紫红色隐隐浮现在$N的" +
				weapon->name() + MAG"上，又迅速消去。\n"NOR, me);	
	}

	data = ([
		"name":		"天上白玉京",
		"target":	me,
		"att_3":	"random",
		"att_3c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);	
	return;
}

