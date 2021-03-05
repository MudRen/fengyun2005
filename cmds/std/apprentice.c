// apprentice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	object ob, old_app;
    	mapping family, skills;
    	int i, score_cost;
    	string *skname;

    	if( !arg ) return notify_fail("指令格式：apprentice|bai [cancel]|<对象>\n");

    	if( arg=="cancel" ) {
        	old_app = me->query_temp("pending/apprentice");
        	if( !objectp(old_app) )
            	return notify_fail("你现在并没有拜任何人为师的意思。\n");
        	write("你改变主意不想拜" + old_app->name() + "为师了。\n");
        	tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
        	me->delete_temp("pending/apprentice");
        	return 1;
    	}

    	if( !(ob = present(arg, environment(me)))
        	|| !ob->is_character() )
        	return notify_fail("你想拜谁为师？\n");

    	if( mapp(me->query("family")))
        if(me->query("family/privs")==1)
            	return notify_fail("你曾经是一帮之主，不能再拜别人为师了。\n");
        else if(me->query("family/privs")==-1)
            	return notify_fail("你是一帮之主，不能再拜别人为师了。\n");
    
    	if(!ob->visible(me))
    		return notify_fail("对方看不见你，怎么拜师啊？\n");
    		
    	if( !living(ob) )
        	return notify_fail("你必须先把" + ob->name() + "弄醒。\n");

    	if( ob==me ) return notify_fail("拜自己为师？好主意....不过没有用。\n");

    	if( me->is_apprentice_of(ob) ) {
        	message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n", me, ob);
        	ob->re_rank(me);
        	return 1;
    	}

    	if( !mapp( ob->query("family") ) )
        	return notify_fail(ob->name() + "无意收徒，你无法拜他为师。\n");
    
    	if( userp(ob) && (int) ob->query("family/privs") != -1 )
        	return notify_fail("不是掌门人不可收徒．\n");
        	
    	if((string)me->query("family/family_name") ==(string)ob->query("family/family_name"))
        if((int)me->query("family/generation") <= (int)ob->query("family/generation"))
            	return notify_fail(ob->name()+"的辈分并不比你高！\n");
    
    	score_cost = ob->query("score_cost") ? ob->query("score_cost") : 1000;
    	if (!me->query("family")
    		|| me->query("family/family_name") == ob->query("family/family_name")) 
    		score_cost = 0;
    	
    	if (me->query("score")< score_cost) {
    		message_vision("$N说：你的声望太差，我不想收你为徒（至少需要"+score_cost+"评价）\n",ob);
    		return 1;
    	}
    	
    	if (!ob->query("class"))
    		return notify_fail("请通知巫师改进此NPC。\n");
    	
    	if (me->query("once_menpai"))
    	if (member_array(ob->query("class"), keys(me->query("once_menpai")))!=-1
    		&& me->query("family/family_name")!= ob->query("family/family_name")
    	    	) {
    		message_vision("$N说：你既然已经不认我这个师傅了，还回来做什么？\n",ob);
    		return 1;
    	}
    	
/*    	if (me->query("family") && !me->query_temp("marks/apprentice_others")
    		&& me->query("family/family_name")!= ob->query("family/family_name")) {
    		message_vision("$N说：江湖中人，最重师徒之义，你还是先和你师傅交代一下吧。\n",ob);
    		return 1;
    	}						-- So many troubles */
    	 
/*
		A 老师， B 新生

		A recruit B, B apprentice, 只要不是同门，并且B不是百姓，B就算是叛师，扣B的score
		B apprentice A, A recruit, 只要不是同门，并且B不是百姓，就算是叛师，扣B的score

*/ 
    	   		   	
    // If the target is willing to recruit us already, we do it.
    	if( (object)ob->query_temp("pending/recruit") == me )
    	{
        	if( mapp(me->query("family")) &&
        			(string)me->query("family/family_name") !=(string)ob->query("family/family_name") 
        			&& (string)me->query("family/title") !="弃徒")
        	{
	            	message_vision("$N决定背叛师门，改投入$n门下！！\n\n"
	                	"$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",me, ob);
	            	if(me->query("score") > score_cost) 
	            		me->add("score", -score_cost);
	            	else
	            		me->set("score",0);
	            	me->add("betrayer", 1);
        	}
        	else message_vision("$N决定拜$n为师。\n\n"
                	"$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",me, ob);

        	ob->recruit_apprentice(me);
        	ob->delete_temp("pending/recruit");
			me->delete_temp("marks/apprentice_others");
				
        	tell_object(ob, "恭喜你新收了一名弟子！\n");
        	family = me->query("family");
        	printf("恭喜您成为%s的第%s代弟子。\n", me->query("family/family_name"),
               		chinese_number( me->query("family/generation")));
			return 1;
	
    	} else {
           	
           	old_app = me->query_temp("pending/apprentice");
        	if( ob==old_app )
            	return notify_fail("你想拜" + ob->name() +"为师，但是对方还没有答应。\n");
        	else if ( objectp(old_app) ) {
            	write("你改变主意不想拜" + old_app->name() + "为师了。\n");
            	tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
        	}
		
			message_vision("$N想要拜$n为师。\n", me, ob);
        	me->set_temp("pending/apprentice", ob );
        	if( userp(ob) ) {
            	tell_object(ob, YEL "如果你愿意收" + me->name()+"为弟子，用 recruit 指令。\n" NOR);
        	} else 
            	ob->attempt_apprentice(me);
	        return 1;
    	}
}


int help(object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : apprentice [cancel]|<对象>[0m
[0;1;37m────────────────────────────────[0m
这个指令能让你拜某人为师，如果对方也答应要收你为徒的话，就会立即行
拜师之礼，否则要等到对方用 recruit 指令收你为弟子才能正式拜师。

请注意你已经有了师父，又背叛师门投入别人门下，每叛一次，在新师傅门
下能学到的所有技能等级会减少20级，并且评价至少会降低1000点。如果你
的评价低于1000点，大部分门派是不会接受你叛师的。

当然，江湖中也有一部分师傅不在乎你是否叛过师。

如果对你的师父使用这个指令，会变成向师父请安，并要求师父给你个合适
的称号。
 
请参考相关指令 expell、recruit
[0;1;37m────────────────────────────────[0m
HELP
        );
    return 1;
}
