// earth-warp.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;
        if(me->query("class")!="taoist")
         	return notify_fail("只有三清宫弟子才可以画符。\n");
   
        if((int)me->query_skill("scratmancy",1) < 20 )
                return notify_fail("往生符需要20级的的三清符术。\n");

        if( sheet->name() != "桃符纸" )
                return notify_fail("往生符要画在桃符纸上！\n");

        if( (int)me->query("mana") < 50 ) 
			return notify_fail("画往生符需要50点法力！\n");
		me->add("mana", -50);
        me->force_status_msg("mana");

        sheet->add_amount(-1);
		seteuid( geteuid(me));
        newsheet = new("/obj/item/magic_seal");
        newsheet->set_name(YEL "往生符" NOR, 
		({ "earth-warp sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->move(me);
        
        me->save();
        message_vision("$N写了一道往生符。\n" NOR, me);
        return 1;
}

int do_warp(string target, object who)
{
        object env, ding;
        env = environment(this_player());
        
        if(environment(this_player())->query("no_fly")
        	||environment(this_player())->query("no_death_penalty"))
    		return notify_fail("此地不能使用往生符。\n");  
        
        if (stringp(this_player()->query_temp("no_move")))
        	return notify_fail(this_player()->query_temp("no_move"));
        
		if (this_player()->query("class")!="taoist") {
			if(!objectp(ding = present("ding", env)))
				return notify_fail("非三清弟子只能在宝鼎处祭符。\n");        
			if (ding->is_character()) 
	 	 		return notify_fail("非三清弟子只能在宝鼎处祭符。\n");
		}
		
		if (this_player()->is_fighting())
    		return notify_fail("哎呀，这个时候烧符是没有用的，还是撒脚丫子逃吧。\n");  

        message("vision",
                HIB + this_player()->name() + "祭起一张往生符。\n"
"忽然四周吹起了一阵凉飕飕的阴风，阴风之中彷佛有许多人影在晃动...\n"
                "然後一阵火光突然爆起！\n" NOR, env);
        message("vision", "可是...." + this_player()->name() + 
"已经不见了。\n", environment(this_player()), ({this_player()}));
	this_player()->start_busy(4);
	call_out("move_him",1+random(4),this_player());
	return 1;
}


int move_him(object me)
{
        message("vision",
                CYN 
"你只觉得身子不断下坠，一直下坠，一直下坠，一直下坠，一直下坠 .....\n"
                NOR     
"不知道什麽时候，你发现你其实一直都站在坚硬的地面上，可是四周的景物\n"
                        "却不一样了....\n\n\n", me);
        TASK_D->flying_risk(me);
        me->move(AREA_DEATH"gate");
        return 1;
}
 


/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/
