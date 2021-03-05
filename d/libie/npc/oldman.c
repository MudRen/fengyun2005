
#include <ansi.h>

inherit NPC;
int weapon();
void create()
{
        set_name("磨刀老人", ({ "old man","man" }) );
        set("long",
"一头乱发，衰老而略有些瘸脚的磨刀老人。他的一双手十分稳定，每当他看到
一把好刀剑的时候，总不由自主发出连连赞叹。据说他曾经是一个有名的铸造
"YEL"兵器"NOR"的大师，却不知为何抛弃了家业来到了这个小镇，据说是为了要寻找铸剑
的"YEL"灵石。\n"NOR);

    	set("attitude", "friendly");

    	set("age",72);
   		set("agi", 50);

    	set("combat_exp", 500000);
		set_skill("unarmed",150);
		set_skill("parry",150);
		set_skill("dodge",150);
		
	set("inquiry", ([
		"weapon" : 	(: weapon :),
		"兵器" : 	(: weapon :),
		"bingqi" : 	(: weapon :),
		"灵石":	"传说中的五彩灵石，如果镶嵌在兵器上，便可以增加武器的灵性。\n",
		"灵物":	"传说中的五彩灵石，如果镶嵌在兵器上，便可以增加武器的灵性。\n",
		"stone":	"传说中的五彩灵石，如果镶嵌在兵器上，便可以增加武器的灵性。\n",
                "莲姑" : 	"莲姑是镇上老于头的女儿。\n",
                "樊夫人":	"樊夫人是风云城里的祭剑师。\n",
                "杨铮" : 	"杨铮是这儿的捕头，正在破获一百八十万两镖银的大案。\n",
                "yang" : 	"杨铮是这儿的捕头，正在破获一百八十万两镖银的大案。\n",
                "yang zheng" : 	"杨铮是这儿的捕头，正在破获一百八十万两镖银的大案。\n",
                "正月初三":	"正月初三你都不知道，还算中国人么。\n",
                "di qinglin" : 	"镇上新来的小候爷好象就叫这个名字。\n",
                "狄青麟" : 	"镇上新来的小候爷好象就叫这个名字。\n",
                "离别钩":	"这柄钩无论钩住什么，都会造成离别，如果他钩住你的手，你的
手就要和腕离别；如果它钩住你的脚，你的脚就和腿离别。如果它钩住你的咽喉，
你就要和这个世界离别了。 \n",
		"蓝一尘":	"神眼神剑”蓝大先生，大侠啊！！\n",
		"花四爷":	"花四爷是洛阳首富，前些天忽然在这儿暴毙了。\n",
        ]));
    
    	set("chat_chance", 1);
    	set("chat_msg", ({
			"磨刀老人仰面向天怔怔道：有生之日但能得见那神兵『离别钩』便也算不枉此生了。\n",
    	}) );
	setup();
        carry_object("/obj/armor/cloth")->wear();
}


void init(){
	::init();
    	add_action("do_qian", "imbue");
}

int weapon(){
	object me;
	me = this_player();
	message_vision("$N长叹一声：兵器是有灵性的，有灵性的物品又可以增加武器的灵性，但是灵物难求呀。\n", this_object());
	return 1;
}

int imbue_event(object who, string name, string atr) {

	mapping data;
	data = ([
			"name":		name,
			"target":	who,
			"att_1":	atr,
			"att_1c":	2,
			"mark":		1,
		]);
	REWARD_D->imbue_att(data);	
	return 1;
	
}

int do_qian(string arg){
	object me, weapon, stone;
	string obj, item, prop;
	mapping data;
	
	me = this_player();
	if(!arg) {
		return notify_fail("你要嵌什么东西。\n");
	}
	if(!sscanf(arg, "%s with %s", obj, item)) {
		return notify_fail("格式：ｉｍｂｕｅ 某物 ｗｉｔｈ 某物？\n");
	}
	weapon = present(obj, me);
	stone = present(item, me);
	if(!objectp(weapon) || !objectp(stone)){
		return notify_fail("你没有这件东西。\n");
	}
	if(weapon->query("owner") != me->query("id") || !weapon->query("owner")) {
		return notify_fail("你不可以镶嵌这个东西。\n");
	}
	if(!stone->query("imbue")){
		return notify_fail("这个东西不可以用来镶嵌。\n");
	}
	
/*	if(stone->query("stone_owner")!= me) {
		message_vision(YEL"$N叹口气说：灵石随主，不是你的镶上去也没用。\n"NOR,this_object());
		return 1;
	}*/
		
	message_vision("$N拿起" + stone->name() + "和"+weapon->name()+"端详许久。\n", this_object());
	
	weapon->unequip();
	if(weapon->query("weapon_prop")) {
		prop="weapon_prop/";
	}
	if(stone->query("id") == "topaz") {
		if(me->query("imbue/ystone")) {
			return notify_fail("你已经不可一再镶嵌这个东西了。\n");
		}
		if (!REWARD_D->check_m_success(me,"凝露黄石")){
			message_vision(YEL"$N叹口气说：灵石随主，不是你的镶上去也没用。\n"NOR,this_object());
			return 1;
		}
		message_vision(HIY"\n凝露黄石发出明亮的黄色光芒.... 一缕缕流光飞入"NOR + weapon->name()+"。\n",
				this_object());
			
		// 这个纯粹靠运气，没有任何经验限制
		me->set("imbue/ystone", 1);
		imbue_event(me, "凝露黄石","kar");

	} else if(stone->query("id") == "diamond") {
		if(me->query("imbue/bstone")) {
			return notify_fail("你已经不可一再镶嵌这个东西了。\n");
		}
		if (!REWARD_D->check_m_success(me,"碧海蓝心")){
			message_vision(YEL"$N叹口气说：灵石随主，不是你的镶上去也没用。\n"NOR,this_object());
			return 1;
		}
		message_vision(HIC"碧海蓝心发出莹莹的蓝色光芒.... 一缕缕流光飞入"NOR + weapon->name()+"。\n",
				this_object());
		// 这个大约至少需要L60以上八
		me->set("imbue/bstone", 1);
		imbue_event(me,"碧海蓝心","cps");

	} else if(stone->query("id") == "ruby"){
		if(me->query("imbue/rstone")) {
			return notify_fail("你已经不可一再镶嵌这个东西了。\n");
		}
		if (!REWARD_D->check_m_success(me,"蛰龙赤丹")){
			message_vision(YEL"$N叹口气说：灵石随主，不是你的镶上去也没用。\n"NOR,this_object());
			return 1;
		}
		message_vision(HIR"蛰龙赤丹发出炎炎的红光.... 一缕缕流火飞入"NOR + weapon->name()+"。\n",
				this_object());
		// 这个么，也是有机可乘蹭高手的，特别是Healer，不过，众乐乐就众乐乐吧。
		me->set("imbue/rstone", 1);
		imbue_event(me,"蛰龙赤丹","str");

	} else if(stone->query("id") == "amethist") {
		if(me->query("imbue/pstone")) {
			return notify_fail("你已经不可一再镶嵌这个东西了。\n");
		}
		if (!REWARD_D->check_m_success(me,"幽冥紫晶")){
			message_vision(YEL"$N叹口气说：灵石随主，不是你的镶上去也没用。\n"NOR,this_object());
			return 1;
		}
		message_vision(HIM"幽冥紫晶发出幽幽的紫色光芒.... 一缕缕流霞飞入"NOR + weapon->name()+"。\n",
				this_object());
		
		// 如果有高手罩着，Doable at any EXP RANGE
		imbue_event(me,"幽冥紫晶","agi");
		me->set("imbue/pstone", 1);

	} else if(stone->query("id") == "jade") {
		if(me->query("imbue/gstone")) {
			return notify_fail("你已经不可一再镶嵌这个东西了。\n");
		}
		if (!REWARD_D->check_m_success(me,"天灵翡翠")){
			message_vision(YEL"$N叹口气说：灵石随主，不是你的镶上去也没用。\n"NOR,this_object());
			return 1;
		}
		message_vision(HIG"天灵翡翠发出的澄碧的绿光.... 一缕缕流光飞入"NOR + weapon->name()+"。\n",
				this_object());
		// at least L50+ to beat 76
		me->set("imbue/gstone", 1);
		imbue_event(me,"天灵翡翠","int");

	}
	destruct(stone);
	weapon->save();
	return 1;
}

int accept_object(object me, object obj)
{
	object weapon;
	mixed *inv;
	int i, j;
	string msg;
	
	if (obj->query("real_leavehook"))
	{
	 if (obj->query("hook_owner")== me)
	{ 
		msg = YEL"
磨刀老人双手握钩，以钩尖向天，将钩锋迎展于阳光下。除了他的眼睛外，
他这个人仿佛已经在一瞬间化成了一座石像。他的神、他的气、他的灵、
他的魂，仿佛都已在一瞬间完全投入了他握住的这柄钩里。

磨刀老人缓缓地说：此钩是不祥之物，就象是个天生畸形的人，生来就带
有唳气，所以它一出炉，铸造它的人就因此而死。\n"NOR;

		if (!obj->query("blood"))
		{
			msg += HIR"
你若用此钩，纵能称霸天下，一生中也必然充满悲痛不幸！\n\n"NOR;
			
		} else
		{
			msg += WHT"
可是现在它的唳气已经被化解了，被蓝—尘的血化解了。因为蓝一尘本来
应该是它的主人，却抛弃了它；他虽然没有杀邵大师，邵大师却也算因他
而死的，他已经在这柄钩的精髓里种下了充满怨毒与仇恨的暴唳不祥之气，
只有用他自己的血才有化解得了。

磨刀老人闭上眼睛长长叹息：这都是天意，天意既然要成全你，你已经可
以安心了。你去吧，无论你要去做什么，无论你要去对付什么人，都绝对
不会失败的。		\n"NOR;
			
		}
		message_vision(msg, me);
		return 0;
	}else
	{
		message_vision("磨刀老人说：好一把凶器，只可惜物归非主。\n", me);
		return 0;	
	}
		
	}	
	
	if (obj->query("fake_leavehook"))
	{
		if (obj->query("equipped"))
			obj->unequip();
		obj->set("weapon_prop",0);
		obj->set("name",MAG"断掉的离别钩"NOR);
		obj->set("value",0);
		obj->set("long","一把奇形怪状的兵刃,但是已经断掉了。\n");
        	message_vision(YEL "
磨刀老人小心翼翼地轻抚着离别钩，过了半晌，缓缓道：此等劣物，还是不要留在
人间的好。说罢，磨刀老人弹指一击，离别钩竟“铛”的一声断为两截。\n"NOR,me);
		obj->set("fake_leavehook",0);
		message_vision("磨刀老人将"MAG"断掉的离别钩"NOR"递还给$N。\n"NOR,me);		
		return notify_fail("");
	}	
	
	inv = all_inventory(me);
	j = 0;
	if(obj->query("imbue")) {
		message_vision(YEL"\n$N仔细看了看$n手中的"NOR+obj->name()+YEL"点头道：“好！好！此等灵物，\n可遇而不可求。”\n"NOR,
				this_object(), me);
		
		for(i=0; i<sizeof(inv); i++){
			if(inv[i]->query("owner") == me->query("id") && inv[i]->query("weapon_prop")) {
				weapon = inv[i];
				j++;
			}
		}
		if(!weapon) {
			message_vision(YEL"\n$N又抬头看了看$n道：“灵石还需灵器配，这位" + RANK_D->query_respect(me) + "还是去配把有\n灵气的兵刃吧。”\n"NOR,
					this_object(), me);
			return 0;
		}
		message_vision(YEL"$N又抬头看了看$n道：“既是有缘，你可愿我帮你把它铸嵌在武器上？”\n"NOR,
				this_object(), me);
		tell_object(me,WHT"
格式：imbue 某物 with "+obj->query("id")+"
其中某物必须为自制武器，但是属性将直接增加到你的身上而不在武器上。
也就是说，以后使用任何武器都能得到增益。\n"NOR);
	
	}
	return 0;
}
