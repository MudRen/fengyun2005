// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    	object ob;
    	mapping skill;
    	string  book,liter;
    	int cost, sena;
    	int amount=0;
    	int my_skill, liter_level;
    	string *att_skill = ({ "literate", "unarmed", "force", "foreknowledge", "chanting", "move" });
    
    	if(environment(me)->query("no_fight")||environment(me)->query("no_study") )
        	return notify_fail("你不可以在这里学习。\n");
    	if( me->is_fighting() )
        	return notify_fail("你无法在战斗中专心下来研读新知！\n");
    	if( me->is_busy() )
        	return notify_fail("你上一个动作还没有完成，不能研读新知。\n");

    	if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
        	return notify_fail("指令格式：study <物品> <神数量>\n");
    
    	if(!objectp(ob = present(book, me)) )
	if(!objectp(ob = present(book, environment(me))))
            	return notify_fail("你要读什麽？\n");
    
    	if( !mapp(skill = ob->query("skill")) )
        	return notify_fail("你无法从这样东西学到任何东西。\n");

// added by tie
    	if(stringp(skill["literate"])) liter = skill["literate"];
    		else liter = "literate";
    	if( !me->query_skill(liter, 1) )
        	return notify_fail("你看不懂耶．．，先学学"+SKILL_D(liter)->name()+"吧。\n");

// added by silencer, require a certain level of basic skill to study certain skills.
    	if(skill["liter_level"]) {
    		liter_level = skill["liter_level"];
    		if (me->query_skill(liter,1) <liter_level)
    			return notify_fail("你的"+SKILL_D(liter)->name()+"太差了，领会不了耶（需要"+liter_level+"级）\n");	
		}
    
    	message("vision", me->name() + "正专心地研读" + ob->name()+ "。\n", environment(me), me);
    	if( (int)me->query("combat_exp") < skill["exp_required"] )
    	{
        	write("你的实战经验不足，再怎麽读也没用。\n");
        	return 1;
    	}
    	
    	notify_fail("以你目前的能力，还没有办法学这个技能。\n");
    
        if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
    	{
        	write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
        	return 1;
    	}
    
    	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;
    
 /*   	cost = skill["sen_cost"] + skill["sen_cost"] 
        		* (skill["difficulty"] - (int)me->query_int())/20;
    	cost = cost /2;
    	if(cost < 1) cost = 1;*/
    	
    	cost = 1;		// Oh my god .. enough studying in schools already
    	
    	if( cost > sena)
		return notify_fail("以你目前的能力，你至少要花"+chinese_number(cost)+"点神。\n");
    
    	if( (int)me->query("sen") <= sena)
    	{
        	write("你现在过於疲倦，无法专心下来研读新知。\n");
        	return 1;
    	}

	   	my_skill = me->query_skill(skill["name"], 1);
    	
    	if ( member_array(skill["name"], att_skill) == -1)
    		my_skill = my_skill * SKILL_D(skill["name"])->effective_level(me)/100;
    	else
    		my_skill = my_skill;
    	    	
    	if(my_skill * my_skill * my_skill  > (int)me->query("combat_exp")) {
        	write("以你现在的实战经验，再怎麽读也无法领会。\n");
        	return 1;
    	}
    	me->receive_damage("sen", sena);
    
    	if( !me->query_skill(skill["name"], 1) )
        	me->set_skill(skill["name"], 0);
    	
    	
    	amount = me->query_skill(liter, 1) * 10 + 1;
    	
       	if( amount < 1) amount = 1;  
       		
    	amount = amount*sena/cost;
    	
    	me->improve_skill(skill["name"], amount);
    	write("你研读有关" + SKILL_D(skill["name"])->name() + "的技巧，似乎有点心得（+"+ amount +"）\n");
    	return 1;
}

int help(object me)
{
    write( @HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : study|du <物品名称> <耗费「心神」的量>][0m
[0;1;37m────────────────────────────────[0m

风云中共有四种获取技能的途径：	[1;31m读书（study）[0m
				学习（learn）
				钻研（research）
				练习（practice）

这个指令使你可以从秘笈或其他物品自学某些技巧,
但前提是: 你一定要懂秘笈上的文字，有的书籍也许还有其他的要求。
每次学习的数量与你的读书写字能力有关。
可以学到的最高等级与你的经验等级相关。

注意：提高六类基本属性的书籍学习系数为100

See also : learn, research, practice

[0;1;37m────────────────────────────────[0m
HELP
        );
    return 1;
}
