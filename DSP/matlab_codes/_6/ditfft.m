function [Xk] = ditfft(xn, N)
    t = 1:N;
    WWr = exp(-1i * 2 * pi / N * [0:N/2-1].'); % 旋转因子
    % 蝶形运算开始
    M = log2(N); % “级”的数量
    % 码位倒置
    Xk = permute(reshape(xn, 2 * ones(1, M)), M:-1:1);
    Xk = Xk(:);
    N2 = N / 2;
    Num_of_Group = N2; % 每一级中组的个数初始值
    Interval_of_Group = 1; % 每一级中组与组之间的间距

    for m = 0:M-1 % “级”循环开始
        Wr = WWr(1:Num_of_Group:end);
        gMatrix2 = reshape(t, Interval_of_Group, 2, Num_of_Group);
        gMatrix21 = reshape(gMatrix2(:, 1, :), N2, 1);
        gMatrix22 = reshape(gMatrix2(:, 2, :), N2, 1);
        if(m == 0)
            XKtemp = Xk(gMatrix22); % 第0级，蝶形运算式
        elseif(m == 1)
            XKtemp = Xk(gMatrix22);
            XKtemp(2:2:end) = XKtemp(2:2:end) * Wr(2); % 第1级，蝶形运算式
        else
            ss = repmat(Wr, Num_of_Group, 1);
            XKtemp = Xk(gMatrix22) .* ss; % 第m级，第g组的蝶形运算式1
        end
        Xk(gMatrix22) = Xk(gMatrix21) - XKtemp; % 第m级，蝶形运算式
        Xk(gMatrix21) = Xk(gMatrix21) + XKtemp;
        Interval_of_Group = Interval_of_Group * 2; % 递推
        Num_of_Group = Num_of_Group / 2; % 递推
    end
    
    A = xn;
    v = floor(log2(N));
    WN = exp(-1i * 2 * pi / N);
    for m = 1:v
        B = A;
        for k = 0:2^(v-m+1):N-1
            for K = 0:2^(v-m)-1
                p = k + K;
                q = p + 2^(v-m);
                % 基于DIT_FFT的修改
                r = 2^(m-1) * mod(p, 2^(v-m+1));
                B(p+1) = A(p+1) + A(q+1);
                B(q+1) = (A(p+1) - A(q+1)) * WN^r;
            end
        end
        A = B;
    end
    
    NI = N / 2;
    for I = 1:N-1
        if I >= NI
            t = A(I+1);
            A(I+1) = A(NI+1);
            A(NI+1) = t;
        end
        T = N / 2;
        while NI >= T
            NI = NI - T;
            T = T / 2;
        end
        NI = NI + T;
    end
    Xk = A;
    disp('X[k]:');
    disp(Xk);
end
