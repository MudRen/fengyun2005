// hj 内基本指令

int do_who_in_hj()
{
    object rooms;
    mapping info;

    rooms = find_object( HJ_DIR+ "room_door_hj" );
    if( !rooms ) rooms = load_object( HJ_DIR + "room_door_hj" );
    if( !rooms ) return errs("发生意外错误，无法查询。\n");
    write( rooms->who_in_hj()[ "info" ] );
    return 1;
}

int do_hjtop()
{
    object out_room;

    out_room = find_object( HJ_OUT_ROOM );
    if( !out_room )
        return errs("现在无法查看记录。\n");
    write(HIW"
       『幻境·遥远传说之起缘·幽灵显现』
"+out_room->get_TOP_pic()+"\n"NOR);
    return 1;
}

// 有BUG 55555555 已改正，并且优化了一下下。  naihe 2:36 03-10-24
// 接纳玩家 pah (xsmarter) 的建议，加入了放弃技能的指令。
// 改了列表方式，虽然比之前的烦琐，但能够根据我的需要来排序。
int do_gsks( string arg )
{
    object me = this_player();
    int i, amount, temp;
    string *key, msg, clcl, cl, pic, lv_pic, t1, t2;
    mapping all_skills, all_damages;

    string *list;


    if( !me_ok(me) ) return 0;

    all_skills = me->query_temp("hj_game_skills");
    all_damages = me->query_temp("hj_game_damages");

    if( !all_skills || !mapp(all_skills) || sizeof(all_skills) < 1 ||
        !all_damages || !mapp(all_damages) || sizeof(all_damages) < 1 )
        return errs("你并未学得任何 幻境 内的技能。\n");

    if( !arg ) arg = ".";

    if( sscanf(arg, "-d %s", msg) )
    {
        if( undefinedp( all_skills[msg] ) || undefinedp( all_damages[msg] ) )
            return errs("你并不懂得这项幻境内的技能。\n");

        arg = all_skills[msg];
        me->delete_temp("hj_game_skills/"+msg );
        me->delete_temp("hj_game_damages/"+msg );
        me->delete( "huanjing2003/last_skills_name/"+ msg );
        me->delete( "huanjing2003/last_skills_lv/"+ msg );
        me->save();
        message_vision( "$N逆运技能，把自己所懂得的「"+arg+"」散去了。\n",me);
        return 1;
    }

    // 下面开始以固定排序，列出玩家所懂得的技能。
    list = ({ "heal", "hfzj", "hyzj", "llzj", "ydzj", "dhzj", "fhzj", "gszj", });


    clcl = NOR + WHT;
    pic = "◆";
    msg = clcl +
          "╭───────┬─┬─────┬─────┬─────────╮\n" +
          "│    技   能   │LV│ 运用(yun)│ 绝技(pfm)│    效     果     │\n" +
          "├───────┼─┼─────┼─────┼─────────┤\n";


    for( i=0;i<sizeof(list);i++ )
    {
        if( undefinedp( all_skills[list[i]] ) || undefinedp( all_damages[list[i]] ) )
            continue;

        // 上色、特殊技提示及绝招提示
        cl = "";
        t1 = "   ----   ";
        t2 = "   ----   ";
        switch( list[i] )
        {
            case "heal" : cl = CYN; t1 = "克制(kz)"; break;
            case "hfzj" : cl = HIW; t1 = "翔空(xk)"; t2 = "狂风(kf)"; break;
            case "hyzj" : cl = HIM; t1 = "聪敏(cm)"; t2 = "暴雨(by)"; break;
            case "llzj" : cl = HIC; t1 = "力量(ll)"; t2 = "惊雷(jl)"; break;
            case "ydzj" : cl = HIG; t1 = "光芒(gm)"; t2 = "迅电(xd)"; break;
            case "dhzj" : cl = HIB; t1 = "守护(sh)"; t2 = "夺魂(dh)"; break;
            case "fhzj" : cl = HIR; t1 = "热情(rq)"; t2 = "火焰(hy)"; break;
            case "gszj" : cl = HIY; t1 = "寻石(xs)"; t2 = "巨石(js)"; break;
        }

        // 加效果标记，让人一眼可以看出是否能yun, pfm 以及技能高低
        if( all_damages[list[i]] > 99 )
            all_damages[list[i]] = 99;
        // 这一句实际上和 me->set_temp() 同样效果。莫非 mapping 也是类似“指针”的？
        // 例如： mapping test = objecttt->query("lalala");
        //        objecttt->delete("lalala");
        // 那么这个时候， lalala 的值，也成为“0”了！反之亦然。
        temp = all_damages[list[i]];

        if( t1 != "   ----   " )
        {
            if( temp >= YUN_LvNeed ) t1 = "●" + t1;
            else t1 = "○" + t1;
        }
        if( t2 != "   ----   " )
        {
            if( temp >= PFM_LvNeed ) t2 = "●" + t2;
            else t2 = "○" + t2;
        }
        lv_pic = "";
        while( temp>9 )
        {
            lv_pic += pic;
            temp -= 10;
        }
        if( strlen(lv_pic) > 18 ) lv_pic = lv_pic[0..17];

        msg += sprintf( clcl+"│%s%s(%s)"+clcl+"│%2d"+clcl+"│%-10s"+clcl+"│%-10s"+clcl+"│"+cl+"%-18s"+clcl+"│\n"+clcl,
            cl, all_skills[list[i]],list[i], 
            all_damages[list[i]],t1, t2, lv_pic );
        // 技能数量 +1
        amount ++;
    }

    // 为了今后若有扩展时，也可以显示新技能
    // 这一段未完善，需要看加的是什么技能再考虑更改。
    key = keys( all_damages );
    for( i=0; i<sizeof( key ); i++ )
    {
        // 已在前面处理过了，或者技能设置有误，跳过
        if( member_array(key[i],list) != -1 || undefinedp( all_skills[ key[i] ] ) )
            continue;
        // 不加入颜色设置
        msg += sprintf( clcl+"│%s(%s)"+clcl+"│%2d"+clcl+"│%-10s"+clcl+"│%-10s"+clcl+"│"+cl+"%-18s"+clcl+"│\n"+clcl,
            all_skills[key[i]], key[i], 
            all_damages[key[i]], "   ----   ","   ----   ","");
            amount ++;
    }
    // 没有通过检测的技能
    if( !amount )
        return errs("你并未学得任何 幻境 内的技能。\n");
    msg += clcl+ "╰───────┴─┴─────┴─────┴─────────╯\n"NOR;
    write( "  以下是你学得的幻境内技能(共"+chinese_number(amount)+"项)：\n" + msg + "  如需要放弃某项技能，请使用指令：<gsks -d 技能名>  例如：gsks -d heal\n  请注意，输入指令将直接放弃该技能，并无法恢复！\n");
    return 1;
}

int do_ghp()
{
    object me=this_player();
    string color, temp, temp2, temp3;
    int hp,hp_max, iii;

    if( !me_ok(me) ) return 0;

    hp=me->query_temp("hj_hp");
    hp_max=me->query_temp("hj_hp_max");

    color = HIB;
    if( hp > (hp_max * 2/10) ) color = HIR;
    if( hp > (hp_max * 4/10) ) color = HIM;
    if( hp > (hp_max * 6/10) ) color = HIY;
    if( hp > (hp_max * 8/10) ) color = HIG;
    if( hp > hp_max ) color = HIC;

    if( !temp = query("find_name") )
        temp = "神秘国度";
    switch( temp )
    {
        case "风之国度": temp = HIW+temp+NOR;break;
        case "雨之国度": temp = HIM+temp+NOR;break;
        case "雷之国度": temp = HIC+temp+NOR;break;
        case "电之国度": temp = HIG+temp+NOR;break;
    }
    temp2 = "";
    if( me->query_temp("hj_special/xk") ) temp2 += HIW"「翔空」"NOR;
    if( me->query_temp("hj_special/cm") ) temp2 += HIM"「聪敏」"NOR;
    if( me->query_temp("hj_special/ll") ) temp2 += HIC"「力量」"NOR;
    if( me->query_temp("hj_special/gm") ) temp2 += HIG"「光芒」"NOR;
    if( me->query_temp("hj_special/kz") ) temp2 += CYN"「克制」"NOR;
    if( me->query_temp("hj_special/sh") ) temp2 += HIB"「守护」"NOR;
    if( me->query_temp("hj_special/rq") ) temp2 += HIR"「热情」"NOR;
    if( me->query_temp("hj_special/xs") ) temp2 += HIY"「寻石」"NOR;

    if( temp2 == "" ) temp2 = " ---";

    temp3 = "";
    iii = me->query_temp("hj_game_mepower");
    while( iii >4 )
    {
        temp3 += "◆";
        iii -= 5;
    }
    if( strlen( temp3 ) > 20 ) temp3 = temp3[0..19] + ">>>>";

    write( sprintf("【 %s ‖ LV "HIY"%d"NOR" ‖ 气息：%s%d"NOR"/"HIG"%d"NOR" ‖ 得分："HIY"%d"NOR" ‖ 基本力量："HIY"%s"NOR" ‖ 累计杀死NPC "HIM"%d"NOR" 个 】\n【 技能运用中：%s 】\n"NOR,
        temp,me->query("huanjing2003/lv"),color,
        hp, hp_max, me->query_temp("hj_score"),temp3, me->query("huanjing2003/kill_npc"),temp2 ) );
    return 1;
}

// heal 方式更新，可以实现自动恢复。
int do_gheal(string arg)
{
    object target,me=this_player();

    if( !me_ok(me) ) return 0;

    if(!me->query_temp("hj_game_skills/heal") || !me->query_temp("hj_game_damages/heal") )
        return errs("你并不懂得恢复技能。\n");

    if(!arg || arg == me->query("id") ) target=me;
    else target=present( arg,environment( me ) );
    if( !target ) return errs("你要帮谁恢复气息？\n");
    if( !target->is_character() ) return errs("这不是活物。\n");
    if( !living(target) ) return errs("还是先等这人醒来再说吧。\n");
    if( !target->query_temp("hj_hp") || !target->query_temp("hj_hp_max") )
        return errs("这人没有丝毫气息，还是免了吧。\n");

    // 本指令亦可帮NPC恢复气息（将有迷题型NPC需要玩家去帮助） :)
    // 已不可帮助NPC恢复气息。
    if( me->query_temp("hj_need_waiting") == "fighting" || me->query_temp("hj_fighting") )
            return errs("你还在战斗中，要疗伤得先停下来(halt / ht)。\n");

    if( me->query_temp("hj_healing") )
        return errs("你已在运用恢复之技。\n");

    if( me->is_busy() )
        return errs("你还忙着呢。\n");

    if(target == me )
    {
        if( me->query_temp("hj_hp") > (me->query_temp("hj_hp_max") *9/10 ) )
            return errs("你还健康得很，不必调和气息。\n");
        message_vision(CYN"$N"NOR+CYN"定下心来，静静地调和自己的气息。\n"NOR,me);
    }
    else
    {
        if( present( "hj temp leave obj", target )      // 已经暂时离开游戏了，不能帮他恢复hp
          || target->query("hj_game/npc")
          || target->query_temp("huanjing") != "start"
        )
            return errs("你不能帮助这个人恢复气息。\n");

        if(target->query_temp("hj_hp") > (target->query_temp("hj_hp_max") *9/10) )
            return errs("这人还健康得很，不必调和气息。\n");
        if( me->query_temp("hj_hp") < 100 )
            return errs("你自顾不暇，还为别人疗伤？\n");
        message_vision(CYN"$N"NOR+CYN"把手掌贴在$n"NOR+CYN"的背上，运起「恢复之技」来。\n"NOR, me, target );
    }

    me->set_temp("hj_healing", target);
    me->set_temp("hj_need_waiting", "healing");

    remove_call_out("healing");
    call_out("healing", 1, me );
    return 1;
}

void healing( object me)
{
    object env_me,env_target, target;
    int heal_lv, heal_hp;

    if( !me || !me_ok(me) )
        return;
    if( !me->query_temp("hj_need_waiting")
      || me->query_temp("hj_need_waiting") != "healing"
    )
        return;
    target = me->query_temp( "hj_healing" );
    if( !target
      || !target->query_temp("huanjing")
      || target->query_temp("huanjing") != "start"
      || !target->query_temp("hj_hp")
      || target->query_temp("hj_hp") <1
      || !target->query_temp("hj_hp_max")
      || present( "hj temp leave obj", target )
    )
         return hj_halt( CYN"$N"NOR+CYN"内劲一撤，停止了运用恢复之技。\n"NOR );
    env_target = environment( target );
    env_me = environment( me );
    if( !env_target || env_target != env_me || !env_target->query("room_mark") 
     || env_target->query("room_mark") == 1 )
        return hj_halt( CYN"$N"NOR+CYN"内劲一撤，停止了运用恢复之技。\n"NOR );
    // 基本判断通过。
    if( target->query_temp("hj_hp") > (target->query_temp("hj_hp_max") *9/10) )
    {
        if( me == target )
            return hj_halt( CYN"$N"NOR+CYN"调息已顺，长长地舒了一口气。\n"NOR);
        return hj_halt( CYN"$N"NOR+CYN"见得$n"NOR+CYN"已经调息顺畅，撤回了掌来。\n"NOR);
    }

    if( me->is_busy() )
    {
        remove_call_out("healing");
        call_out("healing", 1, me );
        return;
    }
    heal_lv = me->query_temp("hj_game_damages/heal");
    heal_hp = (heal_lv / 2 + random(heal_lv / 2 ));  // lv 100 = 50 + random(50)
    // 雨之国度主动技能效果  使用恢复之技能时效力增强
    if( me->query_temp( "hj_game_find" ) == "yu" )
        heal_hp += (heal_hp / 3) + random(heal_hp/5);
    if(target == me)
    {

        // 飞火之技唯一体现(1)，使用 heal 时降低忙时
        if( me->query_temp("hj_special/rq") )
            me->start_busy(1)+random(2);
        else me->start_busy(2+random(2));

        me->add_temp("hj_hp", heal_hp );
        if(me->query_temp("hj_hp") > me->query_temp("hj_hp_max") )
            me->set_temp("hj_hp", me->query_temp("hj_hp_max") );
        message_vision(CYN"$N"NOR+CYN"定心调和气息，只觉得伤势恢复了些。\n"NOR,me);
        tell_object( me, sprintf("当前： %d / %d \n",
            me->query_temp("hj_hp"), me->query_temp("hj_hp_max") ) );

        /* 取消
        // 运用这个技能，将可能损失一点力量
        if( !random(me->query_temp("hj_game_mepower") * 3 )
          && me->query_temp("hj_game_mepower") > 20 )
        {
            me->add_temp("hj_game_mepower",-1);
            tell_object(me,HIY"你只觉得元气恢复了许多，但力气却似乎小了。\n"NOR);
        }
        */
        // 但也可能获得等级提升
        if( !random( me->query_temp("hj_game_damages/heal") * 2 ) )
        {
            me->add_temp("hj_game_damages/heal",1);
            if(me->query_temp("hj_game_damages/heal") > 99)
                me->set_temp("hj_game_damages/heal",99);
            else tell_object(me,HIY"你对「恢复之技」的领会又进了一层！\n"NOR);
        }
        remove_call_out("healing");
        call_out("healing", 1, me );
        return;
    }

    if( me->query_temp("hj_hp") < 100 )
        return hj_halt( CYN"$N"NOR+CYN"正在帮助$n"NOR+CYN"疗伤，却发现自己气息不畅，只得罢手。\n"NOR);


    // 飞火之技唯一体现(2)，使用 heal 时降低忙时
    if( me->query_temp("hj_special/rq") )
        me->start_busy( 1+random(3) );
    else
        me->start_busy(3+random(3));
    // 取消此设置
    // 若是为非NPC人物（即玩家）疗伤，对方会有忙时。
    //    if( !target->query("hj_game/npc") )
    //        target->start_busy(2+random(2));
    target->add_temp("hj_hp", heal_hp );

    if(target->query_temp("hj_hp") > target->query_temp("hj_hp_max") )
        target->set_temp("hj_hp", target->query_temp("hj_hp_max") );

    message_vision(CYN"$N"NOR+CYN"全力施行为$n"NOR+CYN"疗伤，只见得$n"NOR+CYN"的脸色好转了许多。\n"NOR, me, target);
    // 帮助他人(无论是否NPC)，将获得一小点的加分，但需要消耗自身的气息。
    // 已更改，需要消耗自己气息（小量），但不会有得分。
    me->add_temp("hj_hp",-random( heal_lv /3 ) );
    message_vision(CYN"$N"NOR+CYN"聚精会神，转眼间脸上已现出疲惫之色！\n"NOR,me);
    remove_call_out("healing");
    call_out("healing", 1, me );
    return;
}

int do_hjquit(string arg)
{
    object qxd,me = this_player();

    if( !me_ok(me) ) return errs("你不得使用本指令。\n");

    if ( !arg || (arg!= "fail" && arg!="ok") )
        return errs(HIG"\n             <hjquit> 指令使用提示：

< hjquit fail >     放弃所有的成绩，立刻退出 幻境 游戏。
                      "HIR"使用此指令将减少你的1点贡献度，请慎用。"NOR"
< hjquit ok >       以正常方式退出（类似使用 回归之镜），
                      但你必须有 500 分以上的当前得分，并且
                      需要一定的 已进行游戏 时间。
\n"NOR);

    if ( arg == "fail" )
    {
        if( me->query("shenzhou/pts") < 1 )
            return errs("你连1点贡献度都没有，不得使用本指令。\n");
        write("你输入了强制退出指令，视作失败的情况退出 幻境 1 游戏。"HIR"本指令将扣除你一点贡献度！\n"NOR);
        me->add("shenzhou/pts", -1);
        me->set_temp("hj_hp",-1);
        me->start_busy(5);
        return 1;
    }

    if( me->is_busy() || me->query_temp("hj_need_waiting") )
        return errs("你还忙着呢。\n");

    qxd = present( "qixing deng",me);
    if(!qxd || qxd->query("my_master") != me )
        return errs("你身上没有七星灯？……或者你不是它的主人？……\n");

    if( !qxd ->query("can_quit_hj") )
        return errs("你才刚进来游戏没多久，确实要退出请使用 <hjquit fail> 指令作放弃退出。\n"HIR"请注意，使用 fail 类型指令退出将会扣减你的贡献度1点，请慎用！\n"NOR);

    if( !me->query_temp("hj_score") || me->query_temp("hj_score") < 500 )
        return errs("你当前的游戏得分不够 500 分，确实要退出请使用 <hjquit fail> 指令作放弃退出。\n"HIR"请注意，使用 fail 类型指令退出将会扣减你的贡献度1点，请慎用！\n"NOR);

    if( qxd ->query("wait_over") == "yes" )
        return errs("你的游戏时间即将结束，请稍为等待即可。\n");

    message_vision(CYN"$N"NOR+CYN"高声叫道：“现实映现！”\n"NOR,me);
    write(HIR"使用本指令，将扣除你的 500 点游戏得分！\n"NOR);
    me->add_temp("hj_score" , - 499);
    me->start_busy(3);

    qxd->set("use_huigui","yes");

    message_vision(WHT"只见一阵白雾不知从何处飘来，愈来愈浓……\n"NOR,me);
    return 1;
}

int do_hjtime()
{
    object me = this_player();
    int enter_time = me->query_temp("hj_enter_time");;

    write(sprintf( "你进入游戏的时间是 %s ，现在的时间是 %s ，\n游戏时间%s 。\n",
        !enter_time ? "未知" : ctime_format( enter_time ),  ctime_format(),
        !enter_time ? "未知" : sprintf( "共 %d 小时 %d 分 %d 秒", 
            ( time() - enter_time ) / 3600,
            ( ( time() - enter_time ) % 3600 ) / 60,
            ( ( time() - enter_time ) % 3600 ) % 60 ) ) );

    return 1;
}

int do_halt()
{
    object me = this_player(),target;
    string temp;

    if( !me_ok(me) )
        return errs( "什么？\n");
    if( ( !me->query_temp("hj_healing") && !me->query_temp("hj_fighting")) ||
        !me->query_temp("hj_need_waiting") )
    {
        me->delete_temp( "hj_need_waiting" );
        return errs( "你现在并不在战斗或疗伤中。\n");
    }
    temp = me->query_temp("hj_need_waiting");
    if( temp == "healing" )
    {
        target = me->query_temp("hj_healing");
        if( target == me )
        {
            hj_halt(CYN"$N"NOR+CYN"急吸一口大气，停止了调整气息。\n"NOR);
            return 1;
        }
        hj_halt(CYN"$N"NOR+CYN"掌力一收，停下了对$n"NOR+CYN"的疗伤。\n"NOR);
        return 1;
    }
    hj_halt(CYN"$N"NOR+CYN"虚晃一招，跃出战圈不打了。\n"NOR);
    return 1;
}

// 若主人（玩家）不在，本物件会被清除，所以不用考虑
// 延时中发生的意外。
void delete_special_sks( object me, string sks, string sks_name )
{
    // 话这么说，基本安全总要做的
    if( !me || !me_ok(me) )
        return;
    // 如果用 wiztools 停止了运用，这里再停一次，岂非搞笑？所以要看看它是否还在用。
    if( !me->query_temp("hj_special/"+sks) )
        return;
    me->delete_temp("hj_special/"+ sks);
    message_vision( HIY"\n只见围着$N"HIY"的一圈微光隐退，「"+sks_name+"」技能的效力消失了。\n\n"NOR, me);
}

int do_gyun( string arg )
{
    // 这个指令的扩展不好，不管了，就这样罢。
    // 实在需要扩充时，再改为好扩充的方式。
    object me = this_player();
    string *sp_sks = ({ "xk", "cm", "ll", "gm", "kz", "sh", "rq", "xs" }), find_name;
    int HpNeed = 50, hpneed, del_time;
    // HpNeed 可能浮动增加 20%
    mapping sks_sks = ([
        "xk": ({ "翔空", "风之国度", "hfzj", "呼风之技" }), 
        "cm": ({ "聪敏", "雨之国度", "hyzj", "唤雨之技" }),
        "ll": ({ "力量", "雷之国度", "llzj", "落雷之技" }),
        "gm": ({ "光芒", "电之国度", "ydzj", "引电之技" }),
        "kz": ({ "克制",       "--", "heal", "恢复之技" }),
        "sh": ({ "守护",       "--", "dhzj", "夺魂之技" }),
        "rq": ({ "热情",       "--", "fhzj", "飞火之技" }),
        "xs": ({ "寻石",       "--", "gszj", "滚石之技" }),
    ]);


    if( !me_ok(me) )
    {
        write("什么？\n");
        return 1;
    }

    if( !arg || member_array( arg, sp_sks ) == -1 )
    {
        write( sprintf("
      你的特殊技能运用情况：
"WHT"=====================================
"HIW"    翔空(xk)   >>>>>>   %s
"HIM"    聪敏(cm)   >>>>>>   %s
"HIC"    力量(ll)   >>>>>>   %s
"HIG"    光芒(gm)   >>>>>>   %s
"NOR+CYN"    克制(kz)   >>>>>>   %s
"HIB"    守护(sh)   >>>>>>   %s
"HIR"    热情(rq)   >>>>>>   %s
"HIY"    寻石(xs)   >>>>>>   %s
"NOR+WHT"=====================================\n"NOR, 
    me->query_temp("hj_special/xk") ? "运用中" : "--",
    me->query_temp("hj_special/cm") ? "运用中" : "--",
    me->query_temp("hj_special/ll") ? "运用中" : "--",
    me->query_temp("hj_special/gm") ? "运用中" : "--",
    me->query_temp("hj_special/kz") ? "运用中" : "--",
    me->query_temp("hj_special/sh") ? "运用中" : "--",
    me->query_temp("hj_special/rq") ? "运用中" : "--",
    me->query_temp("hj_special/xs") ? "运用中" : "--") );
        return 1;
    }

    // 忙时限制有调整，这是为了可以在战斗中或疗伤中运用技能
    if( me->query_busy() > 5 )
    {
        write("你现在实在是太忙了(忙时5秒以上)，无法静心运用特殊技能。\n");
        return 1;
    }
    // 不得重复运用。
    if( me->query_temp("hj_special/"+ arg) )
    {
        write("你已在运用这个技能。\n");
        return 1;
    }
    // 需要大量气息
    hpneed = HpNeed + random(HpNeed/5);
    if( me->query_temp("hj_hp") < (hpneed + 50) )
    {
        write("你的气息太弱，无法运用特殊技能。\n");
        return 1;
    }
    if( me->query_temp("hj_game_damages/"+ sks_sks[arg][2] ) < YUN_LvNeed )
    {
        write(sprintf("你的「%s」等级不够，无法运用「%s」技能。\n",
            sks_sks[arg][3], sks_sks[arg][0] ) );
        return 1;
    }
    // 效力
    del_time = me->query_temp("hj_game_damages/" + sks_sks[arg][2] ) * 4 / 5;
    // 若是F,Y,L,D四种特殊技，非本国子民效力减半
    if( sks_sks[arg][1] != "--" && query("find_name") != sks_sks[arg][1] )
        del_time /= 2;

    me->set_temp("hj_special/"+arg, del_time );
    // 这个 set 的值无实用意义，可使用任意非零值。
    me->add_temp("hj_hp", -hpneed);
    //    me->start_busy( me->query_busy() + 1 );
    // 取消技能运用的忙时。因其本身需要大量气息，故不必限制忙时。
    // 各特殊技运用时的描述
    switch( sks_sks[arg][0] )
    {
        // #########################################################
        case "翔空":
            message_vision(HIW"\n只见$N"HIW"张开双手，仰天闭目口诵咒文，霎时间平地起风，$N"HIW"竟至浮身半空！\n"
                "这正是风之「翔空」秘籍！\n\n"NOR, me);
            break;
        // #########################################################
        case "聪敏":
            message_vision(HIM"\n只见$N"NOR+HIM"两手互握，低头闭目默念咒文，顿时似有无限灵感纷涌而至！\n"
                "这正是雨之「聪敏」秘籍！\n\n"NOR, me);
            break;
        // #########################################################
        case "力量":
            message_vision(HIC"\n只见$N"HIC"双目圆睁单拳向天，口中大喝一声，顿时全身筋骨噼啪作响，气势惊人！\n"
                "这正是雷之「力量」秘籍！\n\n"NOR, me);
            break;
        // #########################################################
        case "光芒":
            message_vision(HIG"\n只见$N"HIG"右手摊掌缓缓前伸，刹那间掌心凝聚一团耀眼光芒，瞬间笼罩全身！\n"
                "这正是电之「光芒」秘籍！\n\n"NOR, me);
            break;
        // #########################################################
        case "克制":
            message_vision( CYN"\n只见$N"NOR+CYN"双掌合十，默默地念了几句咒文，顿时一阵清风掠起，让人心境平和，再无烦忧。\n"
                "这正是恢复之技「克制」秘籍！\n\n"NOR, me );
            del_time *= 4;  // 效力持久
            break;
        // #########################################################
        case "守护":
            message_vision( HIB"\n只见$N"HIB"双手食指并置额心，口念咒文，四处即时和起一阵凄厉之声，似有灵体护身一般！\n"
                "这正是夺魂之技「守护」秘籍！\n\n"NOR, me );
            break;
        // #########################################################
        case "热情":
            message_vision( HIR"\n只见$N"HIR"左手握拳置于左腰之旁，右手伸出食、中二指，满脸笑容，大喊一声：“耶！”\n"
                "这正是飞火之技「热情」秘籍！\n\n"NOR,me);
            break;
        // #########################################################
        case "寻石":
            message_vision( HIY"\n只见$N"HIY"双手紧握放在脸前，闭目喃喃祈祷道：“石头，石头，我要石头……”\n"
                "这正是滚石之技「寻石」秘籍！\n\n"NOR,me);
            break;
        // #########################################################
    }
    call_out( "delete_special_sks", del_time , me, arg, sks_sks[arg][0] );
    write( sprintf( "技能约持续 %d 秒幻境时间有效。\n", del_time ) );
    return 1;
}
