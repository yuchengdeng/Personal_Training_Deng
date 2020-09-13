
int main()
{
    preprocess();
    scanf("%d", &n);
    while (getchar() != '\n')
        ;
    for (int i = 0; i < n; ++i)
    {
        get_x_and_y();

        // 8 bit
        memset(cnr, 0, 256 * sizeof(int));
        for (int j = 0; j < 8000; ++j)
            for (int k2 = 0; k2 < 16; ++k2)
                for (int k4 = 0; k4 < 16; ++k4)
                {
                    char x2 = x[j][1];
                    char u2 = s_r[y[j][1] ^ k2];
                    char u4 = s_r[y[j][3] ^ k4];
                    if ((x2 ^ SHR(x2, 1) ^ SHR(x2, 3) ^ u2 ^ SHR(u2, 2) ^ u4 ^ SHR(u4, 2)) & 1)
                        cnr[k2][k4] += 1;
                }
        for (int k2 = 0; k2 < 16; ++k2)
            for (int k4 = 0; k4 < 16; ++k4)
            {
                if (cnr[k2][k4] > 4000)
                    cnr[k2][k4] -= 4000;
                else
                    cnr[k2][k4] = 4000 - cnr[k2][k4];
            }

        for (;;)
        {
            // other 8 bit
            int max = 0;
            for (int i = 0; i < 16; ++i)
                for (int j = 0; j < 16; ++j)
                    if (cnr[i][j] > max)
                    {
                        max = cnr[i][j];
                        key2 = i;
                        key4 = j;
                    }
            cnr[key2][key4] = 0;
            memset(cnt, 0, 256 * sizeof(int));
            memset(cns, 0, 256 * sizeof(int));
            for (int j = 0; j < 8000; ++j)
                for (int k1 = 0; k1 < 16; ++k1)
                    for (int k3 = 0; k3 < 16; ++k3)
                    {
                        char x1 = x[j][0];
                        char x3 = x[j][2];
                        char u1 = s_r[y[j][0] ^ k1];
                        char u2 = s_r[y[j][1] ^ key2];
                        char u3 = s_r[y[j][2] ^ k3];
                        char u4 = s_r[y[j][3] ^ key4];
                        if ((x1 ^ SHR(x1, 2) ^ SHR(x1, 3) ^ SHR(u1, 3) ^ SHR(u2, 3) ^ SHR(u3, 3) ^ SHR(u4, 3)) & 1)
                            cnt[k1][k3] += 1;
                        if ((x3 ^ SHR(x3, 2) ^ SHR(x3, 3) ^ SHR(u1, 1) ^ SHR(u2, 1) ^ SHR(u3, 1) ^ SHR(u4, 1)) & 1)
                            cns[k1][k3] += 1;
                    }
            for (int k1 = 0; k1 < 16; ++k1)
                for (int k3 = 0; k3 < 16; ++k3)
                {
                    int cnt_ = cnt[k1][k3];
                    int cns_ = cns[k1][k3];
                    if (cnt_ > 4000)
                        cnt_ -= 4000;
                    else
                        cnt_ = 4000 - cnt_;
                    if (cns_ > 4000)
                        cns_ -= 4000;
                    else
                        cns_ = 4000 - cns_;
                    cnt[k1][k3] = cnt_ + cns_;
                }

            // other 16 bit
            for (int cnt16bit = 0; cnt16bit < TOPNUM2; cnt16bit++)
            {
                int max = 0;
                for (int i = 0; i < 16; ++i)
                    for (int j = 0; j < 16; ++j)
                        if (cnt[i][j] > max)
                        {
                            max = cnt[i][j];
                            key1 = i;
                            key3 = j;
                        }
                cnt[key1][key3] = 0;
                raw_key2 = (key1 << 12) | (key2 << 8) | (key3 << 4) | (key4);
                for (raw_key1 = 0; raw_key1 < 65536; ++raw_key1)
                {
                    gen_key();
                    int i = 0;
                    for (; i < MAGIC; ++i)
                    {
                        // SPN
                    }
                    if (i == MAGIC)
                        break;
                }
                if (raw_key1 < 65536)
                    break;
            }
            if (raw_key1 < 65536)
                break;
        }
        put16bit(raw_key1);
        put16bit(raw_key2);
        putchar('\n');
    }
    return 0;
}
