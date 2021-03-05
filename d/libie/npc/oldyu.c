#include <ansi.h>
inherit NPC;

int lian();
int yang();

void create()
{
        set_name("老于头", ({ "old yu", "yu" }) );
        set("gender", "男性" );
        set("age", 65);
        set("per", 10);
        set("long", "一个白发苍苍的老者，呆呆地望着你，似乎有话要说。\n");
        set("attitude", "peaceful");
        set("combat_exp", 100000);
        set("chat_chance", 1);
        set("no_arrest", 1);
        set("chat_msg", ({
		"老于头呆呆地在杨树下石凳上坐着，看著一朵朵杨花飘落，痴痴道：
小铮啊，你可得活着回来啊，莲姑那娃儿。。。还在等你啊。。。\n"
        }) );
        set("inquiry", ([
                "莲姑" : (: lian :),
                "lian gu" : (: lian :),
                "小铮" : (: yang :),
                "杨铮" : (: yang :),
                "yang" : (: yang :),
                "yang zheng" : (: yang :),
                "正月初三":	"小老儿有个侄孙女儿就是正月初三生的。\n",
                "di qinglin" : "镇上新来的小侯爷好象就叫这个名字。\n",
                "狄青麟" : 	"镇上新来的小侯爷好象就叫这个名字。\n",
        ]));
        set("信",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}



int accept_fight(object me)
{
        command("say 老头子哪里是您的对手？");
        return 0;
}
 
int lian()
{
    	object me=this_player();
    	if (REWARD_D->riddle_check(me,"离别")==4)
    	{
    		message_vision("老于头老泪纵横地说：莲姑在九泉之下也可以瞑目了！\n", me);
    		return 1;
    	}
    	
    	if (REWARD_D->riddle_check(me,"离别")==3 || me->query_temp("libie/di_1"))
    	{
    		message_vision("老于头伤心地说道：狄青麟派人害死了我的莲姑，你一定要替她报仇啊！\n", me);
    		return 1;
    	} 
    	
    	if (REWARD_D->riddle_check(me,"离别")==2)
    	{
    	if (me->query_temp("libie/lian_corpse"))
    	{
    		message_vision("老于头痛哭道：莲姑死的好惨，你一定要找出凶手啊！\n", me);
    		return 1;
    	}else
    	{
    		message_vision("老于头焦急地说：莲姑失踪几天了，快想想办法吧。\n",me);
    		return 1;	
    		
    	}
	}
	
    	message_vision("老于头扭过头去，朝屋内挥着手道：莲姑呐，还不端茶水来，招待这位" + RANK_D->query_respect(me) + "。\n", me);
    	message_vision(CYN"老于头摇摇头说：这孩子，打今早儿起就不见人影了。\n"NOR, this_object());
    	return 1;
}

int yang()
{
    	string msg;	
	object me = this_player();;
	
	if (!environment()->query("yu_home"))
	{
		message_vision("老于头茫然地看着你，好像没听到$N的问话。\n"NOR, me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me, "离别"))
	{
		message_vision("老于头说：谢谢你替我送信，小铮就该回来了吧。\n",me);
		return 1;
	}
	
	if (me->query("timer/libie_letter") + 86400 > time())
	{
		message_vision("老于头说：信不是才给你了么？怎么这么快就又来了？\n"NOR, me);
		return 1;	
	}	
	
	if (me->query("timer/libie_refuse") + 1800 > time())
	{
		message_vision("老于头说：你方才还不是大侠士，怎么这么快就变了心意？再好好想想吧。\n"NOR, me);
		return 1;	
	}
		
    	if(me->query_temp("libie/离别钩_送信"))
    	{
        	message_vision("老于头茫然的说道：信不是给你了吗？难道俺认错人了？\n"NOR,me);
    		return 1;
    	}
    	
    set("chat_chance", 0);
	msg = "
老于头“呵呵”傻笑了起来：你问我家小铮啊，他前两天出去办案了。听说
是个大案，一百八十万镖银在咱们县里被人劫了，镖头捕头死了好多，就连
京城里也下来了个什么小侯爷。\n"NOR;
	if (query("信"))
	{
	       	msg += "\n老于头拍了拍头说：对了，里屋里还有小铮摆着的一封信。说是给一位大侠
士，是" + RANK_D->query_respect(me) + "你么？\n"NOR;
	       	add_action("do_answer", "answer");
	       	me->set_temp("libie/answer_yu",1);
	}
	message_vision(msg,me);	
	return 1;
}

int do_answer(string arg)
{
    	object me = this_player();
    	string name = RANK_D->query_self(me);
    	
    	if (!me->query_temp("libie/answer_yu"))	return 0;
    	    	
    	if( arg == "no" )
    	{
        	message_vision(MAG"$N搔了搔头小声道：" + name + "我无甚德行，何敢以侠士自居。\n"NOR, me);
        	message_vision(MAG"老于头目光停滞，长长叹了口气，转头不语。\n"NOR, me);
			me->delete_temp("libie/answer_yu");
			me->set("timer/libie_refuse",time());
        	return 1;
    	}
    	else if( arg == "yes" )
    	{
        	message_vision(CYN"
$N虽红着脸，但一字字答道：" + name + "我虽不才，但仗义扶危，正乃我辈份内之事！\n"NOR, me);
		me->delete_temp("libie/answer_yu");
		if (F_LEVEL->get_level(me->query("combat_exp"))< 30) {
			message_vision(CYN"老于头又看了看$N，叹了口气说：“交给你，我不放心。”\n"NOR,me);
			tell_object(me,"（解此谜题需经验等级三十以上）\n");
			return 1;
		}
		message_vision("
老于头顿时喜笑颜开道：“大侠士啊，请随我进来，信就在里面，我家小铮
临走时说，就这件事儿他还放心不下，这下可好了。”\n
"YEL"老于头转身进了内屋。\n"NOR,me);
        	me->set_temp("libie/离别钩_取信",1);
        	this_object()->move("/d/libie/neishi");
        	return 1;
    	}
    	else
    		return 0;
}

int give_letter(object me)
{	object letter;
	
	if(!present(me,environment())) return 0;
    	message_vision(YEL"老于头颤巍巍的递给$N一封信，转身又向外走去。\n"NOR,me);
	this_object()->move("/d/libie/yard");
	letter=new(__DIR__"obj/letter");
	if (!letter->move(me))
		letter->move(environment(me));
	letter->set("送信人",me);
	this_object()->delete("信");
	set("chat_chance", 1);
	me->delete_temp("libie/离别钩_取信");
	me->set_temp("libie/离别钩_送信",1);
	return 1;
}	


void reset()
{
	set("信",1);
	
}