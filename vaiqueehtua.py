def vai_que_eh_tua(Xb, Yb, Zb, Xd, Yd, Zd, Xp, Yp, Zp):
    t = -Zb / Zd
    if t < 0:
        return "Nem tenta!"

    Xi = Xb + t * Xd
    Yi = Yb + t * Yd
    Zi = Zb + t * Zd

    Xd_new = Xd
    Yd_new = Yd
    Zd_new = -Zd

    if Zd_new == 0:
        return "Nem tenta!"

    t_new = (Zp - Zi) / Zd_new

    Xp_new = Xi + t_new * Xd_new
    Yp_new = Yi + t_new * Yd_new

    if Xp_new == Xp and Yp_new == Yp:
        return "Vai que eh tua!"
    else:
        return "Nem tenta!"


Xb, Yb, Zb = map(int, input().split())

Xd, Yd, Zd = map(int, input().split())

Xp, Yp, Zp = map(int, input().split())


resultado = vai_que_eh_tua(Xb, Yb, Zb, Xd, Yd, Zd, Xp, Yp, Zp)
print(resultado)
