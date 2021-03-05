int errs( string msg )
{
    write( msg );
    return 1;
}

int me_ok(object me)
{
    object env;

    if( !me || me != query("my_master") )
        return 0;
    if( me->query_temp("huanjing") != "start"
      || me->query_temp("hj_hp") < 1
      || !me->query_temp("hj_hp_max")
    )
        return 0;
    env = environment(me);
    if( !env || !env->query("room_mark") )
        return 0;
    return 1;
}

void hj_halt(string msg)
{
    object me = query("my_master");
    if( !me ) return;

    if( msg != "" )
    {
        if( strsrch( msg, "$n" ) == -1 )
            message_vision( msg, me);
        else message_vision( msg, me,
            me->query_temp("hj_healing") ? 
            me->query_temp("hj_healing") :
            me->query_temp("hj_fighting") );
    }

    me->delete_temp("hj_need_waiting");
    me->delete_temp("hj_healing");
    me->delete_temp("hj_fighting");
    delete("pfm_ready");
}

string get_deng_pic( int deng )
{
    string co1 = HIC, co2 = HIB, co3 = BLU;

    switch( deng )
    {
        case 0: return NOR+co1+"
                    ┏━━━━┓
                    ┃"NOR+co3+"●●●  "NOR+co1+"┃
                    ┃"NOR+co3+"●  ●  "NOR+co1+"┃
                    ┃"NOR+co3+"    ●  "NOR+co1+"┃
                    ┃"NOR+co3+"      ●"NOR+co1+"┃
                    ┗━━━━┛\n\n"NOR;

        case 1: return NOR+co1+"
                    ┏━━━━┓
                    ┃"NOR+co3+"●●●  "NOR+co1+"┃
                    ┃"NOR+co2+"●  "NOR+co3+"●  "NOR+co1+"┃
                    ┃"NOR+co3+"    ●  "NOR+co1+"┃
                    ┃"NOR+co3+"      ●"NOR+co1+"┃
                    ┗━━━━┛\n\n"NOR;

        case 2: return NOR+co1+"
                    ┏━━━━┓
                    ┃"NOR+co2+"●"NOR+co3+"●●  "NOR+co1+"┃
                    ┃"NOR+co2+"●  "NOR+co3+"●  "NOR+co1+"┃
                    ┃"NOR+co3+"    ●  "NOR+co1+"┃
                    ┃"NOR+co3+"      ●"NOR+co1+"┃
                    ┗━━━━┛\n\n"NOR;

        case 3: return NOR+co1+"
                    ┏━━━━┓
                    ┃"NOR+co2+"●●"NOR+co3+"●  "NOR+co1+"┃
                    ┃"NOR+co2+"●  "NOR+co3+"●  "NOR+co1+"┃
                    ┃"NOR+co3+"    ●  "NOR+co1+"┃
                    ┃"NOR+co3+"      ●"NOR+co1+"┃
                    ┗━━━━┛\n\n"NOR;

        case 4: return NOR+co1+"
                    ┏━━━━┓
                    ┃"NOR+co2+"●●●  "NOR+co1+"┃
                    ┃"NOR+co2+"●  "NOR+co3+"●  "NOR+co1+"┃
                    ┃"NOR+co3+"    ●  "NOR+co1+"┃
                    ┃"NOR+co3+"      ●"NOR+co1+"┃
                    ┗━━━━┛\n\n"NOR;

        case 5: return NOR+co1+"
                    ┏━━━━┓
                    ┃"NOR+co2+"●●●  "NOR+co1+"┃
                    ┃"NOR+co2+"●  ●  "NOR+co1+"┃
                    ┃"NOR+co3+"    ●  "NOR+co1+"┃
                    ┃"NOR+co3+"      ●"NOR+co1+"┃
                    ┗━━━━┛\n\n"NOR;

        case 6: return NOR+co1+"
                    ┏━━━━┓
                    ┃"NOR+co2+"●●●  "NOR+co1+"┃
                    ┃"NOR+co2+"●  ●  "NOR+co1+"┃
                    ┃"NOR+co2+"    ●  "NOR+co1+"┃
                    ┃"NOR+co3+"      ●"NOR+co1+"┃
                    ┗━━━━┛\n\n"NOR;

        case 7: return NOR+co1+"
                    ┏━━━━┓
                    ┃"NOR+co2+"●●●  "NOR+co1+"┃
                    ┃"NOR+co2+"●  ●  "NOR+co1+"┃
                    ┃"NOR+co2+"    ●  "NOR+co1+"┃
                    ┃"NOR+co2+"      ●"NOR+co1+"┃
                    ┗━━━━┛\n\n"NOR;
    }

    return "你的七星灯里还有八个灯亮着！！！！！！！真是太厉害了！！！\n";
}

