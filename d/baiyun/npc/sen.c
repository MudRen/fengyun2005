// 八部众之摩呼罗迦王 夙兴夜寐 沈云星 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 100 DMG 25 ATTACK 71K DODGE 71K PARRY 71K
// 使用以busy为特色的feixiansword。*giggle sinny
// 弹奏上阕广陵散·末世广陵

// A/D/P：等于标准8M。此人可TK。

inherit SMART_NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("沈云星", ({ "shen yunxing","shen","sen"}) );
	set("gender", "男性" );
	set("title",YEL"大光明教 "NOR CYN"摩呼罗迦王"NOR);
	set("nickname",HIB"夙寐夜兴"NOR);
	set("attitude","friendly");
	set("long",	"沈云星一身蓝衫，盘膝端坐在白玉石上，身前平放着一张斑驳\n古琴，琴边是一把辉光长剑。\n");
	set("class","baiyun");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",40);
	set("per",200);
	set("force",2500);
	set("max_force",2500);
	set("force_factor",130+random(100));
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_arrest",1);
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);

	set("chat_chance", 1);
	set("chat_chance", 1);
	set("chat_msg", ({
			"沈云星对你笑道：尊客来访，有失远迎，不知是否愿意一聆"YEL"白云城"NOR"外、"YEL"广陵止息"NOR"？\n",
			}) );

    set("inquiry", ([
        "白云城": "白云"YEL"琴"CYN"棋书画，实是武林一绝。可惜门下心多异志，\n自相殴斗者有之，弃师而去者有之，如何能成气候？",
        "白云":   "白云"YEL"琴"CYN"棋书画，实是武林一绝。可惜门下心多异志，\n自相殴斗者有之，弃师而去者有之，如何能成气候？",
        "教主":   "action沈云星微微笑道：此事不出数月即可见于天下，你何必着急？",
        "魔教":   "action沈云星微微笑道：此事不出数月即可见于天下，你何必着急？",
        "大光明教":   "action沈云星微微笑道：此事不出数月即可见于天下，你何必着急？",
        "西方神教":   "action沈云星微微笑道：此事不出数月即可见于天下，你何必着急？",
        "叶孤城": "叶孤城谋于剑胆，不诚于师，不诚于剑，不诚于人，\n如何能得白云"YEL"飞仙剑法"CYN"要诀？",
        "剑":   "白云飞仙剑以轻灵变幻攻人，虽非下品，却也不得剑道精要。",
        "剑法":   "白云飞仙剑以轻灵变幻攻人，虽非下品，却也不得剑道精要。",
        "飞仙剑法":   "白云飞仙剑以轻灵变幻攻人，虽非下品，却也不得剑道精要。",
        "琴心":   "action沈云星目注遥空云染，淡淡地叹了口气。\n沈云星慢慢合上双眼，一字字道：是我误她．．．\n",
        "琴":   "琴心精研琴技十余载，自然是当世名家。只是不知她为何\n便不曾想过，绝美的琴曲固然可以伤人无形，初学者刺耳的琴音却往\n往更是让人不忍卒听？",
        "琴道":  "琴心精研琴技十余载，自然是当世名家。只是不知她为何\n便不曾想过，绝美的琴曲固然可以伤人无形，初学者刺耳的琴音却往\n往更是让人不忍卒听？",
        "广陵散": "广陵散又名广陵止息，原是上下两阕，白云岛上所传，\n不过是生死离别的下阕，却失落了上阕的精华。殊不知有高山才显出\n平地，有欢乐才衬出哀伤，嵇康其时思念前时的好友，想起昔日的欢\n乐，才作出‘广陵散如今绝矣’的悲叹，是以琴曲的前半后半大不相\n同。",
        "广陵止息":   "广陵散又名广陵止息，原是上下两阕，白云岛上所传，\n不过是生死离别的下阕，却失落了上阕的精华。殊不知有高山才显出\n平地，有欢乐才衬出哀伤，嵇康其时思念前时的好友，想起昔日的欢\n乐，才作出‘广陵散如今绝矣’的悲叹，是以琴曲的前半后半大不相\n同。",


         ]) );



	set_skill("feixiansword",270);
	set_skill("sword",200);

	set_skill("feixian-steps",240);
	set_skill("move",200);
	set_skill("dodge",200);

	set_skill("chessism",400);
	map_skill("force","chessism");

	set_skill("zensword",240);
	set_skill("demosword",240);
	set_skill("zen",200);
	set_skill("xiaodao",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("eagle-claw", 300);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "eagle-claw");
	map_skill("force", "bolomiduo");
	map_skill("dodge","feixian-steps");
	map_skill("move","feixian-steps");
	map_skill("blade","demon-blade");
	map_skill("sword","feixiansword");
	map_skill("parry","feixiansword");
    	
	add_temp("apply/iron-cloth", 200);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	setup();

	carry_object(__DIR__"obj/sensword")->wield();
	carry_object(__DIR__"obj/sencloth")->wear();
	carry_object(__DIR__"obj/paper6");

    set("reward_npc", 1);
	set("difficulty",7);

}


object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[random(sizeof(enemy))];
}

void init()
{
	object ob;
	if (!is_fighting())
	{
		remove_call_out("play_ting");
		delete_temp("playing");
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
	}
}


void greeting(object ob)
{
        object corpse;
		object me = ob;
		object box;
        if( !ob || environment(ob) != environment() || is_fighting() || query("ting_broken")) return;
			message_vision(CYN"沈云星依旧坐在地上，抚琴微笑道：有客远来，云星不及相迎，还请恕罪。\n"NOR,me);
			message_vision(CYN"沈云星两指一拨，古琴叮地一响，摇头道：教主事前便说孤城野心太大，\n不诚于剑，便难诚于心，此事多半落空．．．诚不我欺。\n"NOR,me);
			message_vision(CYN"沈云星轻轻叹息：如此，便只好我自己动手，却还真是麻烦呢。\n"NOR,me);
			return;
}


void killed_enemy(object who)
{
	string msg;
	remove_killer(who);
	who->remove_killer(this_object());
	if (!is_fighting())
	{
		remove_call_out("play_ting");
		delete_temp("playing");
		msg = CYN"\n沈云星微微一笑，摇了摇头，拍了拍身上尘土，将古琴放回膝前。\n\n"NOR;
		message_vision(msg,this_object());
	}
}

object *getenemy()
{
	object *enemy,room,*temp;
	int i;
	room = environment();
	temp = all_inventory(room);
	enemy = ({ });
	for (i=0;i<sizeof(temp) ; i++)
	{
		if (temp[i] == this_object())
			continue;
		if (temp[i]->query("name") == HIW"白鹤"NOR)
			continue;
		if (temp[i]->is_corpse() || !temp[i]->is_character()) continue;
		enemy += ({ temp[i] });
	}
	return enemy;
}

int play_ting(int count)
{
	string msg;
	object *enemy,bird;
	int i;
	enemy = getenemy();
	if (!is_fighting() && !query("ting_broken"))
	{
		remove_call_out("play_ting");
		delete_temp("playing");
		msg = CYN"\n沈云星微微一笑，摇了摇头，拍了拍身上尘土，将古琴放回膝前。\n\n"NOR;
		message_vision(msg,this_object());
		return 1;
	}

	switch (count)
	{
	case 1:
		msg = CYN"\n沈云星径自盘膝而坐，将古琴扶上膝头，稍一按弦，微笑道：＂如此，我就以广陵止息待客。＂\n\n"NOR;
		message_vision(msg,this_object());
		break;
	case 2:
		msg = HIC"\n琴声初起，乐音祥和安宁，舒滑如暖风拂面，如初阳晨曦，不带一丝一毫的烟火之气。\n一切烦忧，都好似随着琴声飘散，你只觉置身于暖春三月的河边草地，眼前是杂花生树\n，群莺乱飞，争强斗狠之心烟消云散。\n\n"NOR;
		message_vision(msg,this_object());
		for (i=0; i<sizeof(enemy); i++)
		{
			tell_object(enemy[i],RED"(你浑身懒洋洋的，提不起一丝劲力。)\n"NOR);
			enemy[i]->perform_busy(1);
		}
		break;
	case 3:
		msg = HIW"\n沈云星微微一笑，指法一转，琴音变得婉转朦胧，如同苏杭一带盛行的丝竹小调。在曲\n声中，你仿佛步入了一幅名家精心绘制的泼墨画卷，见到了深深浅浅层次分明的江南山\n水，见到了若黛远山迷朦烟气中飞过的只只白鹤。\n\n"NOR;
		message_vision(msg,this_object());
		seteuid(getuid());
		for (i=0; i<3+random(4); i++)
		{
	        bird = new(__DIR__"white_crane");
	        bird->move(environment());
	        bird->invocation(this_object(), 500);
			bird->set("possessed", this_object());
		}
		break;
	case 4:
		msg = HIG"\n不知不觉之中曲调又是一变，变得更为欢愉，更为轻快。好像是情人的隅隅细语，好像\n是知己的款款深谈，只听得你心头鹿撞，无限旖旎风光缠绕眼前，不觉心魂俱醉，双颊\n潮红，一口真气渐渐涣散。\n\n"NOR;
		message_vision(msg,this_object());
		for (i=0; i<sizeof(enemy); i++)
			enemy[i]->set("force",enemy[i]->query("force")/2);
		break;
	case 5:
		msg = YEL"\n乐声陡然直落而下，如怨如慕，如泣如诉。好像从春暖花开的时节，忽然把你带到了木\n叶摇落的秋天。沈云星弹奏至此，琴音宛如三峡猿啼，宛如鲛人夜泣，宛如老母倚闾，\n盼望出征儿子的归来，却不知儿子已经成了无定河边的枯骨；宛如楼头怨妇，悔教夫婿\n觅封侯，却不知自己挚爱的丈夫，早已是贪新忘旧；好友生离，娇妻死别，树欲静而风\n不止，子欲养而亲不待，萧瑟凄怆之感，登时溢满胸怀。\n\n"NOR;
		message_vision(msg,this_object());
		for (i=0; i<sizeof(enemy); i++)
		{
			enemy[i]->receive_wound("sen",enemy[i]->query("max_sen")/6,this_object());
			enemy[i]->receive_damage("sen",enemy[i]->query("max_sen")/4,this_object());
			COMBAT_D->report_status(enemy[i]);
		}
		break;
	case 6:
		msg = HIB"\n曲调终于渐次低沉，几至无声。空中余音袅袅，徘徊不散，又似是溶进了阵阵涛声。你\n从物我两忘的境界中渐渐回神，却又觉得意犹未尽，心里空空荡荡，似乎缺了什么，气\n血难以舒畅。\n沈云星抱起膝上古琴，缓缓放到地上，琴弦犹自颤动不息。只听得＂铮＂的一响，摇光\n剑脱鞘而出，辉华四射，而地上古琴五弦竟已一起断绝。\n\n"NOR;

		set("ting_broken",1);
		message_vision(msg,this_object());
		for (i=0; i<sizeof(enemy); i++)
			enemy[i]->perform_busy(3);
		stop_busy();
		return 1;
		break;
	}

	call_out("play_ting",count,count+1);
	perform_busy(10);
	return 0;
}

int kill_ob(object who)
{
	object me;
	int exp_r,busyst;
	::kill_ob(who);

	if (!query_temp("playing") && !query("ting_broken"))
	{
		set_temp("playing",1);
		play_ting(1);
	}
	return 1;
}

void smart_fight()
{
	int i;
	int j;
	object *enemy, who,target,me,weapon,wpx;
	string msg;
	who = this_object();
	me=this_object();
	if (who->is_busy()) return;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2 && enemy[1]->is_zombie())
	{
		who->cast_spell("zombie-bolt");
		return;
	}

	target = select_opponent();
	if (me->query_temp("weapon"))
	{
	//	ccommand("say "+target->name()+" busy "+target->query_busy());
		if (target->query_busy() > 2)
		{
			if (ANNIE_D->check_buff(target,"powerup") || target->query_temp("weapon"))
			{
				map_skill("sword","zensword");
				ccommand("perform menghuankonghua "+target->query("id"));
				map_skill("sword","feixiansword");
			}
			else
			{
				delete("class");
				map_skill("sword","demosword");
				ccommand("perform zhutianjianzhen "+target->query("id"));
				set("class","baiyun");
				map_skill("sword","feixiansword");
			}

		}
		else
		ccommand("perform tianwaifeixian "+target->query("id"));
	}
	else
	{
   		me->add_temp("apply/attack", 220);
       	me->add_temp("apply/damage", 620);
		message_vision(HIR"\n$N纵身而起，脸露狰狞之色，五指微屈成爪形，挟劲风自空中飞扑而下！\n",me,target);
		target->add_temp("combat_no_report",1);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM);
		target->add_temp("combat_no_report",-1);
		if (!target->query_temp("damaged_during_attack"))
			message_vision(HIW"$n"HIW"大惊失色，就地堪堪一滚，$N一击不中，地面上登时多出五个孔洞。\n"NOR,me,target);
		else if (target->query("kee") > 0)
		{
			message_vision(HIY"$n"HIY"大惊失色，纵身闪避，结果被劲风余波所及，如纸鹫般飞到三丈开外。\n"NOR,me,target);
			COMBAT_D->report_status(target);
		}
		else
		{
			message_vision(HIR"只听得一声惨嚎，$N五指已没入$n"HIR"头颅，$n"HIR"顶门血如泉涌，抽搐几下，倒在地上。\n"NOR,me,target);
			target->die();
		}
   		me->add_temp("apply/attack", -220);
       	me->add_temp("apply/damage", -620);
		perform_busy(1);
	}
	return;
}


void die()
{
	object me,owner,enemy,paper,*sy_inv,things;
	int j;
	me = this_object();
	if (!query_temp("last_damage_from"))
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		::die();
		return;
	}
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	

	if (environment(me)->query("short") != "斩蟒台顶" || !REWARD_D->check_m_success(enemy,"王图一梦"))
	{
		set("reward_npc", 0);
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		::die();
		return;
	}

	message_vision(CYN"\n$N叹道：广陵散绝琴弦断，海外星沉剑气消．．．\n$N慢慢合上眼睛，低声道：天要绝这上阕广陵，不能不绝。\n\n"NOR,me,enemy);
	enemy->set("annie/demon_killed_sen",1);
//	REWARD_D->riddle_done(enemy,"野心",100,1); what's this ?
	::die();
	return;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

/*
琴声初起，乐音祥和安宁，舒滑如暖风拂面，如初阳晨曦，不带一丝一毫的烟火之气。
一切烦忧，都好似随着琴声飘散，你只觉置身于暖春三月的河边草地，眼前是杂花生树
，群莺乱飞，你浑身懒洋洋的，提不起一丝力道，争强斗狠之心顿时烟消云散。

沈云星微微一笑，指法一转，琴声变得婉转朦胧，如同苏杭一带盛行的丝竹小调。在曲
声中，你仿佛步入了一幅名家精心绘制的泼墨画卷，见到了深深浅浅层次分明的江南山
水，见到了若黛远山迷朦烟气中飞过的只只白鹤。

不知不觉之中曲调又是一变，变得更为欢愉，更为轻快。好像是情人的隅隅细语，好像
是知己的款款深谈，只听得你心头鹿撞，无限旖旎风光缠绕眼前，不觉心魂俱醉，双颊
潮红，一口真气渐渐涣散。

乐声陡然直落而下，如怨如慕，如泣如诉。好像从春暖花开的时节，忽然把你带到了木
叶摇落的秋天。沈云星弹奏至此，琴音宛如三峡猿啼，宛如鲛人夜泣，宛如老母倚闾，
盼望出征儿子的归来，却不知儿子已经成了无定河边的枯骨；宛如楼头怨妇，悔教夫婿
觅封侯，却不知自己挚爱的丈夫，早已是贪新忘旧。好友生离，娇妻死别，树欲静而风
不止，子欲养而亲不待，萧瑟凄怆之感，登时弥漫胸际。

曲调终于渐次低沉，几至无声。空中余音袅袅，徘徊不散，又似是溶进了阵阵涛声。你
从物我两忘的境界中渐渐回神，却又觉得意犹未尽，心里空空荡荡，似乎缺了什么，气
血难以舒畅。
沈云星抱起膝上古琴，缓缓放到地上，琴弦犹自颤动不息。只听得＂铮＂的一响，摇光
剑辉华四射，而地上古琴五弦竟已一起断绝。

annie 08.11.2003
*/