
int do_gpfm( string arg )
{
    object me = this_player();
    if( !me_ok(me) )
        return 0;
    if( !arg )
        return errs("你准备使用什么绝技？\n");
    if( me->query_temp("hj_need_waiting") == "fighting" || me->query_temp("hj_fighting") )
    {
        set("pfm_ready", arg);
        write("你默默聚劲，准备发出绝技 「"+arg+"」 ！\n");
        return 1;
    }
    write("绝技只能在战斗时发出！\n");
    return 1;
}

int do_gbei( string arg )
{
    object me = this_player();
    string now_bei, msg;

    if( !me_ok(me) ) return 0;

    now_bei = me->query_temp("hj_bei");
    if( !now_bei ) now_bei = ".";
    if( now_bei == "." || now_bei == "hand" || now_bei == "none" )
        msg = "徒手攻击";
    else
    {
        if( strsrch( now_bei , "zj" ) != -1 )
            msg = "使用技能 「"+now_bei+"」";
        else msg = "使用道具 「"+now_bei+"」";
    }

    if( !arg ) return errs( "本指令让你设置在战斗中使用的方式，亦可简化为 <bb> 。
例如： gbei bs jian , 在战斗中将会搜寻你身上以及地上的ID为\"bs jian\"的
       道具，对目标进行道具辅助形式的攻击。
例如： gbei hfzj , 在战斗中将会以技能“呼风之技”，对目标进行技能攻击。

你可以设置例如： gbei jian , 那么当你身上有 \"jian\" 这个ID的道具时，
都会继续使用它们来攻击。

而当你所设置的方式已经无法实现，将自动使用空手攻击，但你的设置会被保留。

如果你希望以空手攻击，请设置： <gbei .>  ，或 <gbei hand> ， 或 <gbei none>。
需要查看自己已经设置的状态，请输入 <gbei ?> 指令。

你现在设置的方式是："+ msg + " \n");

    if( arg == "?" )
        return errs("你现在准备好的战斗方式是："+ msg + " \n");

    me->set_temp("hj_bei", arg );
    now_bei = me->query_temp("hj_bei");
    if( now_bei == "." || now_bei == "hand" || now_bei == "none" )
        msg = "徒手攻击";
    else
    {
        if( strsrch( now_bei , "zj" ) != -1 )
            msg = "使用技能 「"+now_bei+"」";
        else msg = "使用道具 「"+now_bei+"」";
    }
    write("你把战斗方式准备为： "+ msg +" 。\n");
    return 1;
}

// gk 方式更新，实现自动打斗，并加入绝技。
int do_gk(string arg)
{
    //    object me,target,tools;
    //    int damages,me_busy,me_power,target_busy;
    //    string tools_name,target_name,do_att="no",color_name,temp,skills_name,skills_name2;

    object me = this_player(), target;
    string target_id;

    if( !me_ok(me) ) return 0;

    if(!arg) return errs("你想要攻击谁？\n");

    if( me->query_temp("hj_need_waiting") == "healing" || me->query_temp("hj_healing") )
            return errs("你还在疗伤呢，要打架得先停下来(halt / ht)。\n");

    target = present( arg, environment(me) );

    if(!target) return errs("这里没有这个人。\n");
    if(!target->is_character()) return errs("这不是活物！\n");
    if(!target->query_temp("hj_hp") || target->query_temp("hj_hp") <1 )
        return errs(target->query("name")+"没有丝毫幻境里的气息，不必攻击了吧。\n");
    if(!living(target)) return errs("这个游戏里必须是清醒的对手才能攻击。\n");
    if(target == me ) return errs("攻击自己？没必要吧……\n");

/*  允许任何玩家对杀。
// 自己得分不够，不许杀玩家
    if( me->query_temp("hj_score") < 200 && !target->query("hj_game/npc"))
        return errs("你的游戏得分那么低，还是抓紧时间弄分数去吧！\n");

// 不允许杀得分低的玩家
    if( target->query_temp("hj_score") < 200 && !target->query("hj_game/npc"))
        return errs(target->query("name")+"的游戏得分太低，这样做好象不太好吧？\n");
*/


    if( me->query("gender") == "男性" )
        message_vision(HIR"\n只听得$N"HIR"大喝道：『纳命来！』，朝着$n"HIR"抢上便攻！\n\n"NOR, me, target );
    else if( me->query("gender") == "女性" )
        message_vision(HIR"\n只听得$N"HIR"一声矫呼：『受死吧！』，朝着$n"HIR"抢上便攻！\n\n"NOR, me, target );
    else message_vision(HIR"\n只听得$N"HIR"阴侧侧地一笑，更不打话，朝着$n"HIR"抢上便攻！\n\n"NOR, me, target );


    me->set_temp("hj_fighting", target );
    me->set_temp("hj_need_waiting", "fighting");

    // 这里不用 remove_call_out(), 因为该函数内有判断句，多余的 call_out 不作处理。
    call_out("fighting", 1);
    return 1;
}

// 对目标进行一次攻击
void do_attack( object me, object target, int damages )
{
    string describe;
    if( !objectp(me) || !objectp(target) || damages < 1 )
        return;
    // 所谓暴击……
    if( !random(50) )
    {
        message_vision( HIR"忽然一阵"HIY"金光"HIR"闪过，$N"HIR"这一击的威力加强了数倍！\n"NOR, me );
        damages *= 2+random(2);
    }
    // 打NPC时
	if( target->query("hj_game/npc") )
	{
	    // NPC设个标记是你打的
		target->set("killme_by",me->query("id"));
        // 可以得到得分。
        // 电之国度被动技能效果  战斗中得分上涨
        if( me->query_temp("hj_special/gm") )
            me->add_temp("hj_score",1+random( damages / 8 ));
        else
            me->add_temp("hj_score",1+random( damages / 10 ));
    }
    target->hj_get_attack(me);  // 目标执行一个受到攻击的函数，只有 hj npc 才有这个函数
    target->add_temp("hj_hp",-damages);  // 给目标扣血
    // 显示健康状态
    describe = get_health_desc( target->query_temp("hj_hp"), target->query_temp("hj_hp_max") );
    message_vision(NOR"（ $N"+describe+NOR" ）\n"NOR,target);
    // 完毕。
}

void fighting()
{
    object me = query("my_master"), inv_me, inv_target, target, use_tools, srl;
    string fight_type, fight_use, use_skills, color_name, skills_name, describe, temp;
    int damages, me_busy, me_power, target_busy;

    mapping pfm_info;

    if( !me || !me_ok(me) ) return;

    // 玩家已收式(halt)。
    // 这个句子不行，有很小的几率会造成错误。
    //    if( !me->query_temp("hj_fighting") || me->query_temp("hj_need_waiting") != "fighting")
    // 这就可以了 :)
    if( !me->query_temp("hj_need_waiting")
     || me->query_temp("hj_need_waiting") != "fighting")
        return;

    target = me->query_temp("hj_fighting");
    if( !target || environment(me)->query("room_mark") == 1 )
        return hj_halt( HIW"\n$N"HIW"摆了一个收式，停下手来。\n\n"NOR );

    // 目标是玩家，已死亡或有意外
    if( !target->query("hj_game/npc") &&
        ( !target->query_temp("huanjing")
        || target->query_temp("huanjing")!="start"
        || !target->query_temp("hj_hp") || target->query_temp("hj_hp") <1
        || !target->query_temp("hj_hp_max") ) )
             return hj_halt( HIW"\n$N"HIW"摆了一个收式，对着$n"HIW"哈哈一笑，停下手来。\n\n"NOR );

    // 目标不是玩家，已死亡
    if( target->query("hj_game/npc") && 
        ( !target->query_temp("hj_hp") || target->query_temp("hj_hp") < 1 ) )
             return hj_halt( HIW"\n$N"HIW"摆了一个收式，对着$n"HIW"哈哈一笑，停下手来。\n\n"NOR );

    inv_target = environment( target );
    if( !inv_target || inv_target != environment(me) || !inv_target->query("room_mark") )
        return hj_halt( HIW"\n$N"HIW"见"+target->query("name")+HIW"已不在此处，摆了一个收式，罢下手来。\n\n"NOR );

    // 目标携带神人令
    if( (srl=present("shenren ling",target)) )
    {
        message_vision( CYN"$N"NOR+CYN"身上的"+srl->query("name")+NOR+CYN"突然发出一阵光芒！\n"NOR, target );
        return hj_halt( HIB"$N"HIB"忽感一阵莫名的巨大压力，只得罢下手来。\n"NOR );
    }
    // 目标离开游戏
    if( present( "hj temp leave obj", target ) )
    {
        return hj_halt( CYN"$n"NOR+CYN"身形忽隐忽现，竟似并无实体一般！$N"NOR+CYN"只得罢下手来。\n"NOR );
    }
    // 好的，下面准备开始攻击目标。
    // 忙时中，等待下一秒。
    if( me->is_busy() )
    {
        remove_call_out("fighting");
        call_out("fighting", 1);
        return;
    }
    // 可以打了，判断打的形式
    // 防错
    if( !me->query_temp("hj_bei") )
        me->set_temp("hj_bei", "hand");

    fight_type = ".";

    // 有绝技请求，先行判断
    if( query("pfm_ready") )
    {
        // 该函数进行判断并返回信息。
        pfm_info = can_use_pfm( query("pfm_ready"), me, target );
        // 把绝技请求删除
        delete( "pfm_ready" );
        // 如果返回0，则不继续做任何处理。
        if( !mapp(pfm_info) || !sizeof(pfm_info) )
        {
            remove_call_out("fighting");
            call_out("fighting", 1);
            return;
        }
        // 不可用时，将返回提示信息 "err_msg" 给玩家一个提示
        // 必须是 sizeof() 为 7 的数据才是正常的。
        if( sizeof( pfm_info ) != 7 )
        {
            if( !pfm_info || undefinedp( pfm_info[ "err_msg" ] ) )
                tell_object( me, "发生意外，无法使用绝技！\n");
            else tell_object( me, pfm_info[ "err_msg" ] + "！\n");
        }
        // 否则无错误，允许使用该 pfm 。
        // 下边的描述程序中，将完全使用 pfm_info 里提供的数据。
        else fight_type = "pfm";
    }
    // 开始判断其他的情况
    // 玩家设定空手
    fight_use = me->query_temp("hj_bei");

    if( fight_type == "." &&
      (!fight_use || fight_use == "." || fight_use == "hand" || fight_use == "none")
    )
        fight_type = "hand";
    // 攻击类型未确定，继续进行判断。判断是否技能类型。
    // 先查看有无该技能，以及是否气息过弱
    if( fight_type == "." )
    {
        if( fight_use != "heal"
          && me->query_temp( "hj_game_skills/" + fight_use )
          && me->query_temp( "hj_game_damages/"+ fight_use )
        )
        {
            // 有技能，玩家气息是否过低
            if( me->query_temp("hj_hp") < 100 )
            {
                message_vision( HIY"\n$N"HIY"忽然觉得气息不顺，只好放弃技能攻击，改用空手作战。\n\n"NOR, me);
                fight_type == "hand";
                // 强制给他设置徒手战斗
                me->set_temp("hj_bei", "hand");
            }
            // 那么OK，使用技能
            else
            {
                use_skills = fight_use;
                fight_type = "skills";
            }
        }
        // 无该项技能，查找身上的道具
        else
        {
            use_tools = present( fight_use, me );
            // 只能使用身上的，要用就要拣起来。
//            if( !use_tools ) use_tools = present( fight_use, environment( me ) );
            // 无该道具，空手作战
            if( !use_tools ) fight_type = "hand";
            else
            {
                // 找到了，要看是不是能打架的东西
                // 是道具但是不是能用的，转空手
                if( !use_tools->query("hj_game/obj")
                 || !use_tools->query("use_times") || !use_tools->query("power")
                 || !use_tools->query("busy") 
                 ||  ( use_tools->query("hj_game/obj") != "sword"
                    && use_tools->query("hj_game/obj") != "magic" ) )
                    fight_type = "hand";
                // 否则定为可用。
                else fight_type = "tools";
            }
        }
    }

    // 防止未知的错误，理论上来说不会出现
    if( fight_type != "tools" && fight_type != "skills" && fight_type != "pfm" )
        fight_type == "hand";
    // **********************************
    // 好了，下面根据类型进行攻击
    // 根据玩家的力量，确定基本攻击力
    if(!me->query_temp("hj_game_mepower"))
        me->set_temp("hj_game_mepower",5);
    me_power = me->query_temp("hj_game_mepower");

    // 雷之国度被动技能效果  战斗中提升基本力量
    if( me->query_temp("hj_special/ll") )
        me_power = (me_power*2) + random(me_power);
    // 徒手攻击
    if( fight_type == "hand" )
    {
        // 确定攻击力、忙时等
        damages = (me_power * 3 / 4 + random(me_power / 4) );
        me_busy = 2;
        // 攻击描述
        temp = ({
            "挥出一拳",
            "踢出一脚",
            "劈出一掌",
            "侧身一撞",
            "飞身一踢",
        })[ random(5) ];
        // 不使用 message_vision() 的方式
        tell_room(environment(me),CYN"\n"+me->query("name")+NOR+CYN"奋力向"+target->query("name")+NOR+CYN+temp+"！\n"NOR,({me,target}));
        tell_object(target,CYN"\n"+me->query("name")+NOR+CYN"奋力向你"+temp+"，造成了 "HIR""+damages+""NOR+CYN" 点的伤害！\n"NOR);
        tell_object(me,CYN"\n你奋力向"+target->query("name")+NOR+CYN+temp+"，造成了 "HIG""+damages+""NOR+CYN" 点的伤害！\n");
        if( !random(me->query_temp("hj_game_mepower") * 2) )
        {
            write(HIY"你只觉得打拳脚功夫多了，力量似乎又大了些。\n"NOR);
            me->add_temp("hj_game_mepower",1 );
        }
    }
    // 用道具攻击
    if( fight_type == "tools" )
    {
        // 看看是什么类型的道具先
        // 剑类
        if( use_tools->query("hj_game/obj") == "sword" )
        {
            // 先确定攻击力、忙时等
            damages = ( me_power *3 / 4 + random( me_power / 4 ) ) +
                  ( use_tools->query( "power" ) *3 / 4 ) + 
                  random( use_tools->query( "power" ) / 4 );

            if( use_tools->query("busy") == 888 ) me_busy = 0;
            else me_busy = use_tools->query("busy");
            use_tools->add("use_times",-1);
            // 判断 use_tools 使用次数完毕而要 delete 的句子放在后边，
            // 否则此时 delete 了它，后面还要调用，就有BUG BUG。
            // 好，攻击描述
            temp = ({ "攻", "削", "刺", "劈", "挑" })[ random(5) ];
            tell_room(environment(me),CYN"\n"+me->query("name")+NOR+CYN"握起"+use_tools->query("name")+NOR+CYN"向"+target->query("name")+NOR+CYN+temp+"去！\n"NOR,({me,target}));
            tell_object(target,CYN"\n"+me->query("name")+NOR+CYN"握起"+use_tools->query("name")+NOR+CYN"向你"+temp+"来，造成了 "HIR+damages+NOR+CYN" 点的伤害！\n"NOR);
            tell_object(me,CYN"\n你握起"+use_tools->query("name")+NOR+CYN"向"+target->query("name")+NOR+CYN+temp+"去，造成了 "HIG+damages+NOR+CYN" 点的伤害！\n");
        }
        // 否则是魔法水晶类
        else
        {
            // 确定攻击力等
            damages = ( me_power * 3 / 4 + random( me_power / 4 ) ) +
                  ( use_tools->query( "power" ) * 3 / 4 ) + 
                  random( use_tools->query( "power" ) / 4 );
            if( use_tools->query("type") == query("find_name") )
                damages *= 2+random(2);
            if( use_tools->query("busy") == 888 ) me_busy = 0;
            else me_busy = use_tools->query("busy");
            use_tools->add("use_times",-1);
            switch(use_tools->query("type"))
            {
                case "风之国度": color_name=HIW;break;
                case "雨之国度": color_name=HIM;break;
                case "雷之国度": color_name=HIC;break;
                case "电之国度": color_name=HIG;break;
                default:color_name = WHT;
            }
            message_vision(color_name+"\n$N"NOR+color_name+"举起$n"NOR+color_name+"大声呼唤道：“魔法速现！”\n"NOR,me, use_tools);
            tell_room(environment(me),color_name+"只见"+use_tools->query("att_msg")+"向"+target->query("name")+NOR+color_name+"攻去，造成了 "HIG+damages+NOR+color_name+" 点的伤害！\n"NOR,target);
            tell_object(target,color_name+"只见"+use_tools->query("att_msg")+"向你攻来，造成了 "HIR+damages+NOR+color_name+" 点的伤害！\n"NOR);
        }
    }

    // 技能攻击
    if( fight_type == "skills" )
    {
        // 确定攻击力及忙时等
        // 这是一个特殊的地方，使用技能时最多只能有力量的 1/2
        damages = me_power / 4 + random( me_power / 4 ) +  
            ( me->query_temp( "hj_game_damages/"+use_skills ) * 3 / 4 ) + 
              random( me->query_temp( "hj_game_damages/"+use_skills ) / 4 );

        skills_name = me->query_temp("hj_game_skills/"+use_skills);
        me_busy = 2+random(2);

        switch( query("find_name") )
        {
            case "风之国度":
                if(skills_name == "呼风之技")
                damages += damages / 2 ;   // 1.5 倍
                break;
            case "雨之国度":
                if(skills_name == "唤雨之技")
                damages += damages / 2;
                break;
            case "雷之国度":
                if(skills_name == "落雷之技")
                damages += damages / 2;
                break;
            case "电之国度":
                if(skills_name == "引电之技")
                damages += damages / 2;
                break;
        }
        if(skills_name == "飞火之技" || skills_name == "滚石之技")
            damages = 1+(damages/3)+random(damages*2);

        switch( skills_name )
        {
            case "呼风之技" : color_name = HIW; break;
            case "唤雨之技" : color_name = HIM; break;
            case "落雷之技" : color_name = HIC; break;
            case "引电之技" : color_name = HIG; break;
            default: color_name = WHT; break;
        }
        tell_room(environment(me), color_name + "\n"+me->query("name")+NOR+color_name+"运起「"+skills_name+"」向"+target->query("name")+NOR+color_name+"攻去！\n"NOR,({me,target}));
        tell_object(target,color_name+"\n"+me->query("name")+NOR+color_name+"运起「"+skills_name+"」向你攻来，造成了 "HIR+damages+NOR+color_name+" 点的伤害！\n"NOR);
        tell_object(me,color_name+"\n你运起「"+skills_name+"」向"+target->query("name")+NOR+color_name+"攻去，造成了 "HIG+damages+NOR+color_name+" 点的伤害！\n"NOR);

        me->add_temp( "hj_hp", -(3+random(3)) );
        // 使用技能，每次将随机降低自身HP数点。
        // 有机会得到技能提升，难度更大了
        if( !random( me->query_temp("hj_game_damages/"+use_skills) * 2 ) )
        {
            me->add_temp("hj_game_damages/"+use_skills,1);
            if(me->query_temp("hj_game_damages/"+use_skills) > 99)
                me->set_temp("hj_game_damages/"+use_skills,99);
            else tell_object(me,HIY"你对「"+skills_name+"」的领会又进了一层！\n"NOR);
        }
    }
    // 绝技攻击
    if( fight_type == "pfm" )
    {
        // 绝技攻击时，攻击力等完全由绝技函数判定，这里只是加上力量的基本攻击。
        // 绝技攻击的基本攻击力与使用技能时一样，最多只能有力量的 1/2
        damages = me_power / 4 + random( me_power / 4 ) + pfm_info[ "damages" ];
        me_busy = pfm_info[ "me_busy" ];
        me->add_temp( "hj_hp", - pfm_info[ "lost_hp" ] );
        // 描述
        temp = replace_string( pfm_info[ "msg_all" ] , "$N", me->name(1) );
        temp = replace_string( temp, "$n", target->name(1) );
        tell_room(environment(me), temp, ({ me, target }) );

        temp = replace_string( pfm_info[ "msg_me" ] , "$N", me->name(1) );
        temp = replace_string( temp, "$n", target->name(1) );
        tell_object( me,temp );

        temp = replace_string( pfm_info[ "msg_target" ] , "$N", me->name(1) );
        temp = replace_string( temp, "$n", target->name(1) );
        tell_object( target, temp );
    }
    // 好了，所有的描述什么的都搞定了
    // 调用 标准攻击函数进行攻击。
    // ################################################
    do_attack( me, target, damages );
    // ################################################
    // 风之国度被动技能效果，战斗中busy降至最低。
    if( me->query_temp("hj_special/xk") && me_busy )
        me->start_busy(1);
    // 否则正常计算。
    else
        me->start_busy(me_busy);
    // 特别的技能或道具，令对方有忙时
    if( fight_type == "skills" && skills_name =="夺魂之技" )
    {
        me->add_temp( "hj_hp", -(3+random(3)) );
        // 若是使用夺魂之技，将额外需要更多的气息。
        // 夺魂之技特殊技能体现之二(1)，有效抵抗来自玩家的夺魂类攻击的忙时效果
        if( !target->query_temp("hj_special/sh") && !random(10)
            && target->query_busy() < 6 )
        {
            // 99 lv 夺魂技可造成 20 秒忙时
            target_busy = me->query_temp("hj_game_damages/dhzj") / 5;
            if(target_busy < 2) target_busy = 2;
            target->start_busy( target_busy + target->query_busy() );
            tell_room( environment(me), sprintf( HIR"%s"HIR"突然两眼发直，整个人呆住了似的。\n"NOR, target->name(1)), ({me,target}));
            tell_object( target, HIR"你突然两眼发直，整个人呆住了似的。 (造成忙时 "+target_busy+" 秒)\n"NOR );
            tell_object( me, HIR+target->name(1)+HIR+"突然两眼发直，整个人呆住了似的。 (造成忙时 "+target_busy+" 秒)\n"NOR );
        }
    }
    // 夺魂之技特殊技能体现之二(2)，有效抵抗来自玩家的夺魂类攻击的忙时效果
    if( !target->query_temp("hj_special/sh") && !random(5)
        && fight_type == "tools" && target->query_busy() < 6
        && (use_tools->query("id") =="dh sj" || use_tools->query("id")=="dh jian" )  )
    {
        target_busy = 10+random(11);
        target->start_busy( target_busy + target->query_busy() );
        tell_room( environment(me), sprintf( HIR"%s"HIR"突然两眼发直，整个人呆住了似的。\n"NOR, target->name(1)), ({me,target}));
        tell_object( target, HIR"你突然两眼发直，整个人呆住了似的。 (造成忙时 "+target_busy+" 秒)\n"NOR );
        tell_object( me, HIR+target->name(1)+HIR+"突然两眼发直，整个人呆住了似的。 (造成忙时 "+target_busy+" 秒)\n"NOR );
    }
    // 这里才判断是否要 delete use_tools.
    if( fight_type == "tools" && use_tools && use_tools ->query("use_times") <= 0 )
        use_tools->delete_me();
    // 搞定！
    // 电之国度主动技能效果  战斗中可能附加攻击
    if( random(8) == 2 && me->query_temp( "hj_game_find" ) == "dian" )
    {
        message_vision( GRN"忽然不知从哪里引出一道"BLINK+HIG"闪电"NOR+GRN"劈向$N"NOR+GRN"，打个正中！\n"NOR, target );
        damages = (me->query_temp( "hj_game_damages/ydzj" )/2);
        if( damages < 5 )
            damages = 5;
        if( damages > 20 )
            damages = 20;
        // 调用 标准攻击函数进行攻击。
        // ################################################
        do_attack( me, target, damages );
        // ################################################
    }
    // 这里再加一次判断，如果对方死了，直接就 return 了。
    // 目标是玩家，已死亡或有意外
    if( !target->query("hj_game/npc") &&
        ( !target->query_temp("huanjing")
        || target->query_temp("huanjing")!="start"
        || !target->query_temp("hj_hp") || target->query_temp("hj_hp") <1
        || !target->query_temp("hj_hp_max") ) )
             return hj_halt( HIW"\n$N"HIW"摆了一个收式，对着$n"HIW"哈哈一笑，停下手来。\n\n"NOR );
    // 目标不是玩家，已死亡
    if( target->query("hj_game/npc") && 
        ( !target->query_temp("hj_hp") || target->query_temp("hj_hp") < 1 ) )
             return hj_halt( HIW"\n$N"HIW"摆了一个收式，对着$n"HIW"哈哈一笑，停下手来。\n\n"NOR );

    // 好了，循环 :)
    // 如果是更特别的道具，迅隐之剑，将直接调用下一次，而不等待1秒
    if( fight_type == "tools" && use_tools && use_tools->query("id") == "xy jian" )
    {
        fighting();
        return;
    }
    remove_call_out("fighting");
    call_out("fighting", 1);
    return;
}
